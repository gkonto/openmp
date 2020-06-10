#include "auxiliaries.hpp"
#include <iostream>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tools.hpp"

namespace {
    struct Opts {
      int num_threads = 0;
      int nits = 0;
    };
} // namespace


static void parseArgs(int argc, char **argv, Opts &o) {
  if (argc != 3) {
    std::cout << "Specify nits and number of threads" << std::endl;
    exit(1);
  }

  read_value<int>(argv[1], o.nits);
  read_value<int>(argv[2], o.num_threads);
}


static void greetings() {
  timestamp();
  printf("\n");
  printf("FFT_OPENMP\n");
  printf("  C/OpenMP version\n");
  printf("\n");
  printf("  Demonstrate an implementation of the Fast Fourier Transform\n");
  printf("  of a complex data vector, using OpenMP for parallel execution.\n");
  printf("\n");
  printf("  Number of processors available = %d\n", omp_get_num_procs());
  printf("  Number of threads =              %d\n", omp_get_max_threads());
  // Prepare for tests.
  printf("\n");
  printf("  Accuracy check:\n");
  printf("\n");
  printf("    FFT ( FFT ( X(1:N) ) ) == N * X(1:N)\n");
  printf("\n");
  printf("             N      NITS    Error         Time          Time/Call    "
         " MFLOPS\n");
  printf("\n");
}


static void bye() {
  printf("\n");
  printf("FFT_SERIAL:\n");
  printf("  Normal end of execution.\n");
  printf("\n");
  timestamp();
}


/*
  Purpose:
    STEP carries out one step of the workspace version of CFFT2.
  Parameters:
*/
static void step(int n, int mj, double a[], double b[], double c[], double d[],
          double w[], double sgn) {
  double wjw[2];

  int mj2 = 2 * mj;
  int lj = n / mj2;

#pragma omp parallel shared(a, b, c, d, lj, mj, mj2, sgn, w) private(wjw)
#pragma omp for nowait
  for (int j = 0; j < lj; j++) {
    int jw = j * mj;
    int ja = jw;
    int jb = ja;
    int jc = j * mj2;
    int jd = jc;

    wjw[0] = w[jw * 2 + 0];
    wjw[1] = w[jw * 2 + 1];

    if (sgn < 0.0) {
      wjw[1] = -wjw[1];
    }

    for (int k = 0; k < mj; k++) {
      c[(jc + k) * 2 + 0] = a[(ja + k) * 2 + 0] + b[(jb + k) * 2 + 0];
      c[(jc + k) * 2 + 1] = a[(ja + k) * 2 + 1] + b[(jb + k) * 2 + 1];
      double ambr = a[(ja + k) * 2 + 0] - b[(jb + k) * 2 + 0];
      double ambu = a[(ja + k) * 2 + 1] - b[(jb + k) * 2 + 1];
      d[(jd + k) * 2 + 0] = wjw[0] * ambr - wjw[1] * ambu;
      d[(jd + k) * 2 + 1] = wjw[1] * ambr + wjw[0] * ambu;
    }
  }
}


/*
  Purpose:
    CFFTI sets up sine and cosine tables needed for the FFT calculation.
  Parameters:
    Input, int N, the size of the array to be transformed.
    Output, double W[N], a table of sines and cosines.
*/
static void cffti(int n, double w[]) {
    const double pi = 3.141592653589793;
    int n2 = n / 2;
    double aw = 2.0 * pi / ((double)n);
#pragma omp parallel shared(aw, n, w) 
#pragma omp for nowait
    for (int i = 0; i < n2; i++) {
        double arg = aw * ((double)i);
        w[i * 2 + 0] = cos(arg);
        w[i * 2 + 1] = sin(arg);
    }
}


/*
  Purpose:
    MAIN is the main program for FFT_OPENMP.
  Discussion:
    The "complex" vector A is actually stored as a double vector B.
    The "complex" vector entry A[I] is stored as:
      B[I*2+0], the real part,
      B[I*2+1], the imaginary part.
*/
int main(int argc, char **argv) {
  Opts o;
  parseArgs(argc, argv, o);
  omp_set_num_threads(o.num_threads);
  int ln2_max = 20;
  int nits = o.nits;
  static double seed;
  seed = 331.0;
  int n = 1;
  greetings();
  double time = omp_get_wtime();

  // LN2 is the log base 2 of N.  Each increase of LN2 doubles N.
  for (int ln2 = 1; ln2 <= ln2_max; ln2++) {
    n = 2 * n;
    /*
      Allocate storage for the complex arrays W, X, Y, Z.
      We handle the complex arithmetic,
      and store a complex number as a pair of doubles, a complex vector as a
      doubly dimensioned array whose second dimension is 2.
    */
    double *w = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(2 * n * sizeof(double));
    double *y = (double *)malloc(2 * n * sizeof(double));
    double *z = (double *)malloc(2 * n * sizeof(double));

    int first = 1;

    for (int icase = 0; icase < 2; icase++) {
      if (first) {
        for (int i = 0; i < 2 * n; i = i + 2) {
          double z0 = ggl(&seed);
          double z1 = ggl(&seed);
          x[i] = z0;
          z[i] = z0;
          x[i + 1] = z1;
          z[i + 1] = z1;
        }
      } else {
#pragma omp parallel shared(n, x, z) 
#pragma omp for nowait
        for (int i = 0; i < 2 * n; i = i + 2) {
          double z0 = 0.0; /* real part of array */
          double z1 = 0.0; /* imaginary part of array */
          x[i] = z0;
          z[i] = z0; /* copy of initial real data */
          x[i + 1] = z1;
          z[i + 1] = z1; /* copy of initial imag. data */
        }
      }
      // Initialize the sine and cosine tables.
      cffti(n, w);
      // Transform forward, back
      if (first) {
        double sgn = +1.0;
        cfft2(n, x, y, w, sgn, step);
        sgn = -1.0;
        cfft2(n, y, x, w, sgn, step);
        // Results should be same as the initial data multiplied by N.
        double fnm1 = 1.0 / (double)n;
        double error = 0.0;
        for (int i = 0; i < 2 * n; i = i + 2) {
          error = error + pow(z[i] - fnm1 * x[i], 2) +
                  pow(z[i + 1] - fnm1 * x[i + 1], 2);
        }
        error = sqrt(fnm1 * error);
        printf("  %12d  %8d  %12e", n, nits, error);
        first = 0;
      } else {
        double wtime = omp_get_wtime();
        for (int it = 0; it < nits; it++) {
          double sgn = +1.0;
          cfft2(n, x, y, w, sgn, step);
          sgn = -1.0;
          cfft2(n, y, x, w, sgn, step);
        }
        wtime = omp_get_wtime() - wtime;
        double flops = 2.0 * (double)nits * (5.0 * (double)n * (double)ln2);
        double mflops = flops / 1.0E+06 / wtime;
        printf("  %12e  %12e  %12f\n", wtime, wtime / (double)(2 * nits),
               mflops);
      }
    }
    if ((ln2 % 4) == 0) {
      nits = nits / 10;
    }
    if (nits < 1) {
      nits = 1;
    }
    free(w);
    free(x);
    free(y);
    free(z);
  }
  bye();
  std::cout << "Execution Time: " << omp_get_wtime() - time << " second" << std::endl;
  return 0;
}
