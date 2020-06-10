#include "auxiliaries.hpp"
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace {
    struct Opts {
        double epsilon;
    };
}


static void parseArgs(int argc, char **argv, Opts &o) {
  if (argc != 2) {
    std::cout << "Specify epsilon" << std::endl;
    exit(1);
  }
  read_value<double>(argv[1], o.epsilon);
}

static void greetings(int M, int N, double epsilon) {
  timestamp();
  printf("\n");
  printf("HEATED_PLATE\n");
  printf("  C version\n");
  printf("  A program to solve for the steady state temperature distribution\n");
  printf("  over a rectangular plate.\n");
  printf("\n");
  printf("  Spatial grid of %d by %d points.\n", M, N);
  printf("\n");
  printf("  The iteration will be repeated until the change is <= %f\n", epsilon);
}

static void bye() {
    printf("\n");
#ifdef PRINT_TO_FILE
    printf("  Solution written to the output file '%s'\n", output_file);
#endif
    // Terminate.
    printf("\n");
    printf("HEATED_PLATE:\n");
    printf("  Normal end of execution.\n");
    printf("\n");
    timestamp();
}


/*
  Purpose:
    MAIN is the main program for HEATED_PLATE.
  Parameters:
    Commandline argument 1, double EPSILON, the error tolerance.
    Commandline argument 2, char *OUTPUT_FILE, the name of the file into which
    the steady state solution is written when the program has completed.
  Local parameters:
    Local, double DIFF, the norm of the change in the solution from one
  iteration to the next. Local, double MEAN, the average of the boundary values,
  used to initialize the values of the solution in the interior. Local, double
  U[M][N], the solution at the previous iteration. Local, double W[M][N], the
  solution computed at the latest iteration.
*/
int main(int argc, char *argv[]) {
#define M 500
#define N 500
//#define PRINT_TO_FILE
    Opts o;
    parseArgs(argc, argv, o);

  //FILE *fp;
  //char output_file[80];
  double u[M][N];
  double w[M][N];

  greetings(M, N, o.epsilon);
  double diff = o.epsilon;
#ifdef PRINT_TO_FILE
  int success;
  // Read OUTPUT_FILE from the command line or the user.
  if (argc < 3) {
    printf("\n");
    printf("  Enter OUTPUT_FILE, the name of the output file:\n");
    success = scanf("%s", output_file);
  } else {
    success = sscanf(argv[2], "%s", output_file);
  }

  if (success != 1) {
    printf("\n");
    printf("HEATED_PLATE\n");
    printf("  Error reading in the value of OUTPUT_FILE.\n");
    return 1;
  }

  printf("\n");
  printf("  The steady state solution will be written to '%s'.\n", output_file);
#endif

  // Set the boundary values, which don't change.
  for (int i = 1; i < M - 1; i++) {
    w[i][0] = 100.0;
  }
  for (int i = 1; i < M - 1; i++) {
    w[i][N - 1] = 100.0;
  }
  for (int j = 0; j < N; j++) {
    w[M - 1][j] = 100.0;
  }
  for (int j = 0; j < N; j++) {
    w[0][j] = 0.0;
  }

  /*
    Average the boundary values, to come up with a reasonable
    initial value for the interior.
  */

  double mean = 0.0;
  for (int i = 1; i < M - 1; i++) {
    mean = mean + w[i][0];
  }
  for (int i = 1; i < M - 1; i++) {
    mean = mean + w[i][N - 1];
  }
  for (int j = 0; j < N; j++) {
    mean = mean + w[M - 1][j];
  }
  for (int j = 0; j < N; j++) {
    mean = mean + w[0][j];
  }
  mean = mean / (double)(2 * M + 2 * N - 4);

  //  Initialize the interior solution to the mean value.
  for (int i = 1; i < M - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      w[i][j] = mean;
    }
  }

  /*
    iterate until the  new solution W differs from the old solution U
    by no more than EPSILON.
  */
  int iterations = 0;
  int iterations_print = 1;
  printf("\n");
  printf(" Iteration  Change\n");
  printf("\n");
  double ctime1 = omp_get_wtime();

  while (o.epsilon <= diff) {
    //  Save the old solution in U.
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        u[i][j] = w[i][j];
      }
    }

    /*
      Determine the new estimate of the solution at the interior points.
      The new solution W is the average of north, south, east and west
      neighbors.
    */
    diff = 0.0;
    for (int i = 1; i < M - 1; i++) {
      for (int j = 1; j < N - 1; j++) {
        w[i][j] = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1]) / 4.0;

        if (diff < fabs(w[i][j] - u[i][j])) {
          diff = fabs(w[i][j] - u[i][j]);
        }
      }
    }
    iterations++;
    if (iterations == iterations_print) {
      printf("  %8d  %f\n", iterations, diff);
      iterations_print = 2 * iterations_print;
    }
  }
  double ctime2 = omp_get_wtime();
  double ctime = ctime2 - ctime1;

  printf("\n");
  printf("  %8d  %f\n", iterations, diff);
  printf("\n");
  printf("  Error tolerance achieved.\n");
  printf("  CPU time = %f\n", ctime);
#ifdef PRINT_TO_FILE
  // Write the solution to the output file.
  fp = fopen(output_file, "w");

  fprintf(fp, "%d\n", M);
  fprintf(fp, "%d\n", N);

  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      fprintf(fp, "%6.2f ", w[i][j]);
    }
    fputc('\n', fp);
  }
  fclose(fp);
#endif

  bye();
  std::cout << "Execution Time: " << ctime << " seconds" << std::endl;

  return 0;

#undef M
#undef N
}
