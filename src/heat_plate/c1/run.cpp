#include "auxiliaries.hpp"
#include <iostream>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

namespace {
    struct Opts {
      double epsilon;
      int num_threads;
    };
} // namespace

static void parseArgs(int argc, char **argv, Opts &o) {
  if (argc != 3) {
    std::cout << "Specify epsilon and num threads" << std::endl;
    exit(1);
  }

  read_value<double>(argv[1], o.epsilon);
  read_value<int>(argv[2], o.num_threads);
}

static void greetings(int M, int N, double epsilon) {
    printf("\n");
    printf("HEATED_PLATE_OPENMP\n");
    printf("  C/OpenMP version\n");
    printf(
      "  A program to solve for the steady state temperature distribution\n");
    printf("  over a rectangular plate.\n");
    printf("\n");
    printf("  Spatial grid of %d by %d points.\n", M, N);
    printf("  The iteration will be repeated until the change is <= %e\n",
         epsilon);
    printf("  Number of processors available = %d\n", omp_get_num_procs());
    printf("  Number of threads =              %d\n", omp_get_max_threads());
}

static void bye(int iterations, double diff, double wtime) {
    printf("\n");
    printf("  %8d  %f\n", iterations, diff);
    printf("\n");
    printf("  Error tolerance achieved.\n");
    printf("  Wallclock time = %f\n", wtime);

    //Terminate
    printf("\n");
    printf("HEATED_PLATE_OPENMP:\n");
    printf("  Normal end of execution.\n");
}

/*
Purpose:
    MAIN is the main program for HEATED_PLATE_OPENMP.
Local parameters:
    Local, double DIFF, the norm of the change in the solution from one
iteration to the next.

    Local, double MEAN, the average of the boundary values, used to initialize
    the values of the solution in the interior.

    Local, double U[M][N], the solution at the previous iteration.

    Local, double W[M][N], the solution computed at the latest iteration.
*/
int main(int argc, char *argv[]) {
#define M 500
#define N 500

  Opts o;
  parseArgs(argc, argv, o);
  double epsilon = o.epsilon;
  double u[M][N];
  double w[M][N];

  omp_set_num_threads(o.num_threads);
  greetings(M, N, o.epsilon);
  // Set the boundary values, which don't change.
  double mean = 0.0;

#pragma omp parallel shared(w) 
  {
#pragma omp for
    for (int i = 1; i < M - 1; i++) {
      w[i][0] = 100.0;
    }
#pragma omp for
    for (int i = 1; i < M - 1; i++) {
      w[i][N - 1] = 100.0;
    }
#pragma omp for
    for (int j = 0; j < N; j++) {
      w[M - 1][j] = 100.0;
    }
#pragma omp for
    for (int j = 0; j < N; j++) {
      w[0][j] = 0.0;
    }
/*
  Average the boundary values, to come up with a reasonable
  initial value for the interior.
*/
#pragma omp for reduction(+ : mean)
    for (int i = 1; i < M - 1; i++) {
      mean = mean + w[i][0] + w[i][N - 1];
    }
#pragma omp for reduction(+ : mean)
    for (int j = 0; j < N; j++) {
      mean = mean + w[M - 1][j] + w[0][j];
    }
  }
  /*
    OpenMP note:
    You cannot normalize MEAN inside the parallel region.  It
    only gets its correct value once you leave the parallel region.
    So we interrupt the parallel region, set MEAN, and go back in.
  */
  mean = mean / (double)(2 * M + 2 * N - 4);
  printf("\n");
  printf("  MEAN = %f\n", mean);
/*
  Initialize the interior solution to the mean value.
*/
#pragma omp parallel shared(mean, w) 
  {
#pragma omp for
    for (int i = 1; i < M - 1; i++) {
      for (int j = 1; j < N - 1; j++) {
        w[i][j] = mean;
      }
    }
  }
  /*
    iterate until the  new solution W differs from the old solution U
    by no more than EPSILON.
  */
  int iterations = 0;
  int iterations_print = 1;
  printf(" \nIteration  Change\n\n");
  double wtime = omp_get_wtime();

  double diff = epsilon;

  while (epsilon <= diff) {
#pragma omp parallel shared(u, w) 
    {
  // Save the old solution in U.
#pragma omp for
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          u[i][j] = w[i][j];
        }
      }
/*
  Determine the new estimate of the solution at the interior points.
  The new solution W is the average of north, south, east and west neighbors.
*/
#pragma omp for
      for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
          w[i][j] =
              (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1]) / 4.0;
        }
      }
    }
    /*
      C and C++ cannot compute a maximum as a reduction operation.

      Therefore, we define a private variable MY_DIFF for each thread.
      Once they have all computed their values, we use a CRITICAL section
      to update DIFF.
    */
    diff = 0.0;
#pragma omp parallel shared(diff, u, w) 
    {
      double my_diff = 0.0;
#pragma omp for
      for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
          if (my_diff < fabs(w[i][j] - u[i][j])) {
            my_diff = fabs(w[i][j] - u[i][j]);
          }
        }
      }
#pragma omp critical
      {
        if (diff < my_diff) {
          diff = my_diff;
        }
      }
    }

    iterations++;
    if (iterations == iterations_print) {
      printf("  %8d  %f\n", iterations, diff);
      iterations_print = 2 * iterations_print;
    }
  }
  wtime = omp_get_wtime() - wtime;

  bye(iterations, diff, wtime);
  return 0;

#undef M
#undef N
}

