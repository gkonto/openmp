#include <iostream>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tools.hpp"

/*
Purpose:
UPDATE updates positions, velocities and accelerations.

Discussion:
The time integration is fully parallel.

A velocity Verlet algorithm is used for the updating.

x(t+dt) = x(t) + v(t) * dt + 0.5 * a(t) * dt * dt
v(t+dt) = v(t) + 0.5 * ( a(t) + a(t+dt) ) * dt
a(t+dt) = f(t) / m

Parameters:

Input, int NP, the number of particles.
Input, int ND, the number of spatial dimensions.
Input/output, double POS[ND*NP], the positions.
Input/output, double VEL[ND*NP], the velocities.
Input, double F[ND*NP], the forces.
Input/output, double ACC[ND*NP], the accelerations.
Input, double MASS, the mass.
Input, double DT, the time step.
*/
void update(int np, int nd, double pos[], double vel[], double f[],
            double acc[], double mass, double dt)
{
  double rmass = 1.0 / mass;

  for (int j = 0; j < np; j++) {
    for (int i = 0; i < nd; i++) {
      pos[i + j * nd] = pos[i + j * nd] + vel[i + j * nd] * dt +
                        0.5 * acc[i + j * nd] * dt * dt;
      vel[i + j * nd] = vel[i + j * nd] +
                        0.5 * dt * (f[i + j * nd] * rmass + acc[i + j * nd]);
      acc[i + j * nd] = f[i + j * nd] * rmass;
    }
  }
}

/*
COMPUTE computes the forces and energies.

Discussion:
The computation of forces and energies is fully parallel.

The potential function V(X) is a harmonic well which smoothly
saturates to a maximum value at PI/2:

v(x) = ( sin ( min ( x, PI/2 ) ) )^2

The derivative of the potential is:

dv(x) = 2.0 * sin ( min ( x, PI/2 ) ) * cos ( min ( x, PI/2 ) )
= sin ( 2.0 * min ( x, PI/2 ) )

Parameters:
Input, int NP, the number of particles.
Input, int ND, the number of spatial dimensions.
Input, double POS[ND*NP], the positions.
Input, double VEL[ND*NP], the velocities.
Input, double MASS, the mass of each particle.
Output, double F[ND*NP], the forces.
Output, double *POT, the total potential energy.
Output, double *KIN, the total kinetic energy.
*/
static void compute(int np, int nd, double pos[], double vel[], double mass,
             double f[], double *pot, double *kin)
{
  double d;
  double d2;
  double PI2 = 3.141592653589793 / 2.0;
  double rij[3];

  double pe = 0.0;
  double ke = 0.0;

  for (int k = 0; k < np; k++) {
    // Compute the potential energy and forces.
    for (int i = 0; i < nd; i++) {
      f[i + k * nd] = 0.0;
    }

    for (int j = 0; j < np; j++) {
      if (k != j) {
        d = dist(nd, pos + k * nd, pos + j * nd, rij);
        // Attribute half of the potential energy to particle J.
        if (d < PI2) {
          d2 = d;
        } else {
          d2 = PI2;
        }

        pe = pe + 0.5 * pow(sin(d2), 2);

        for (int i = 0; i < nd; i++) {
          f[i + k * nd] = f[i + k * nd] - rij[i] * sin(2.0 * d2) / d;
        }
      }
    }

    // Compute the kinetic energy.
    for (int i = 0; i < nd; i++) {
      ke = ke + vel[i + k * nd] * vel[i + k * nd];
    }
  }

  ke = ke * 0.5 * mass;

  *pot = pe;
  *kin = ke;
}


void update(int np, int nd, double pos[], double vel[], double f[],
            double acc[], double mass, double dt);
/*
Purpose:
R8MAT_UNIFORM_AB returns a scaled pseudorandom R8MAT.

Discussion:
This routine implements the recursion
seed = 16807 * seed mod ( 2^31 - 1 )
unif = seed / ( 2^31 - 1 )

The integer arithmetic never requires more than 32 bits,
including a sign bit.

Parameters:
Input, int M, N, the number of rows and columns.
Input, double A, B, the limits of the pseudorandom values.
Input/output, int *SEED, the "seed" value.  Normally, this
value should not be 0.  On output, SEED has
been updated.

Output, double R[M*N], a matrix of pseudorandom values.
*/
void r8mat_uniform_ab(int m, int n, double a, double b, int *seed, double r[])
{
  const int i4_huge = 2147483647;

  if (*seed == 0) {
    fprintf(stderr, "\n");
    fprintf(stderr, "R8MAT_UNIFORM_AB - Fatal error!\n");
    fprintf(stderr, "  Input value of SEED = 0.\n");
    exit(1);
  }

  int k = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      k = *seed / 127773;

      *seed = 16807 * (*seed - k * 127773) - k * 2836;

      if (*seed < 0) {
        *seed = *seed + i4_huge;
      }
      r[i + j * m] = a + (b - a) * (double)(*seed) * 4.656612875E-10;
    }
  }
}


/*
Purpose:
INITIALIZE initializes the positions, velocities, and accelerations.
Parameters:
Input, int NP, the number of particles.
Input, int ND, the number of spatial dimensions.
Output, double POS[ND*NP], the positions.
Output, double VEL[ND*NP], the velocities.
Output, double ACC[ND*NP], the accelerations.
*/
static void initialize(int np, int nd, double pos[], double vel[], double acc[])
{
  // Set positions.
  int seed = 123456789;
  r8mat_uniform_ab(nd, np, 0.0, 10.0, &seed, pos);

  // Set velocities.
  for (int j = 0; j < np; j++) {
    for (int i = 0; i < nd; i++) {
      vel[i + j * nd] = 0.0;
    }
  }

  // Set accelerations.
  for (int j = 0; j < np; j++) {
    for (int i = 0; i < nd; i++) {
      acc[i + j * nd] = 0.0;
    }
  }
}

/*
  Discussion:
    MD implements a simple molecular dynamics simulation.
    The velocity Verlet time integration scheme is used.
    The particles interact with a central pair potential.
    This program is based on a FORTRAN90 program by Bill Magro.

  Usage:
    md nd np step_num dt
    where:
    * nd is the spatial dimension (2 or 3);
    * np is the number of particles (500, for instance);
    * step_num is the number of time steps (500, for instance).
    * dt is the time step (0.1 for instance)
*/
int main(int argc, char *argv[]) {
  double dt = 0.0;
  double mass = 1.0;
  int nd = 0;
  int np = 0;
  int step_num = 0;

  timestamp();
  std::cout << std::endl;
  std::cout << "Molecular Dynamics" << std::endl;
  std::cout << "  C++ version" << std::endl;
  std::cout << "  A molecular dynamics program." << std::endl;

  // Get the spatial dimension.
  getSpatialDimension(argv, argc, nd);
  //  Get the number of particles.
  getNumberOfParticles(argv, argc, np);
  //  Get the number of time steps.
  getNumberOfTimeSteps(argv, argc, step_num);
  //  Get the time steps.
  getTimeSteps(argv, argc, dt);

   // Report.
  std::cout << std::endl;
  std::cout << "  ND, the spatial dimension, is " << nd << std::endl;
  std::cout << "  NP, the number of particles in the simulation, is " << np
            << std::endl;
  std::cout << "  STEP_NUM, the number of time steps, is " << step_num
            << std::endl;
  std::cout << "  DT, the size of each time step, is " << dt << std::endl;

  // Allocate memory.
  double *acc   = new double[nd * np];
  double *force = new double[nd * np];
  double *pos   = new double[nd * np];
  double *vel   = new double[nd * np];

  /*
  This is the main time stepping loop:
  Compute forces and energies,
  Update positions, velocities, accelerations.
  */
  std::cout << std::endl;
  std::cout << "  At each step, we report the potential and kinetic energies."
            << std::endl;
  std::cout << "  The sum of these energies should be a constant." << std::endl;
  std::cout << "  As an accuracy check, we also print the relative error"
            << std::endl;
  std::cout << "  in the total energy." << std::endl;
  std::cout << std::endl;
  std::cout << "      Step      Potential       Kinetic        (P+K-E0)/E0"
            << std::endl;
  std::cout << "                Energy P        Energy K       Relative "
               "Energy Error"
            << std::endl;
  std::cout << std::endl;

  int step_print = 0;
  int step_print_index = 0;
  int step_print_num = 10;

  double ctime = omp_get_wtime();

  double e0 = 0.0;
  double kinetic = 0.0;
  double potential = 0.0;

  for (int step = 0; step <= step_num; step++) {
    if (step == 0) {
      initialize(np, nd, pos, vel, acc);
    } else {
      update(np, nd, pos, vel, force, acc, mass, dt);
    }

    compute(np, nd, pos, vel, mass, force, &potential, &kinetic);

    if (step == 0) {
      e0 = potential + kinetic;
    }

    if (step == step_print) {
      printf("  %8d  %14f  %14f  %14e\n", step, potential, kinetic,
             (potential + kinetic - e0) / e0);
      step_print_index = step_print_index + 1;
      step_print = (step_print_index * step_num) / step_print_num;
    }
  }

  // Report timing.
  ctime = omp_get_wtime() - ctime;
  std::cout << std::endl;
  std::cout << "  Elapsed cpu time: " << ctime << "seconds." << std::endl;

  // Free memory.
  delete[] acc;
  delete[] force;
  delete[] pos;
  delete[] vel;

  // Terminate.
  std::cout << std::endl;
  std::cout << "MD" << std::endl;
  std::cout << "  Normal end of execution." << std::endl;
  std::cout << std::endl;
  timestamp();

  return 0;
}

