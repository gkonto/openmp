#include "auxiliaries.hpp"
#include "prime.hpp"
#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

/*
  Purpose:

   PRIME_NUMBER_SWEEP does repeated calls to PRIME_NUMBER.
  Parameters:
    Input, int N_HI, the last value of N.
    each iteration.
*/
static void prime_number_sweep(int n_hi) {
  printf("\n");
  printf("TEST01\n");
  printf("  Call PRIME_NUMBER to count the primes from 1 to N.\n");
  printf("\n");
  printf("         N        Pi          Time\n");
  printf("\n");

  int primes = prime_number(n_hi);

  printf("  %8d  %8d  %14f\n", n_hi, primes, ctime);
}

namespace {
struct Opts {
  int max = 0;
};
} // namespace

void parseArgs(int argc, char **argv, Opts &o) {
  if (argc != 2) {
    std::cout << "Specify max boundary" << std::endl;
    exit(1);
  }
  read_value<int>(argv[1], o.max);
}
/******************************************************************************/
/*
  Purpose:
    MAIN is the main program for prime_TEST.
*/
int main(int argc, char **argv) {
  Opts o;
  parseArgs(argc, argv, o);
  timestamp();
  printf("\n");
  printf("prime_TEST\n");
  printf("  C version\n");
  printf("  Test the prime library.\n");

  double start = omp_get_wtime();
  prime_number_sweep(o.max);

  // Terminate.
  printf("\n");
  printf("prime_TEST\n");
  printf("  Normal end of execution.\n");
  printf("\n");
  timestamp();

  std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds"<< std::endl;

  return 0;
}
/******************************************************************************/

/******************************************************************************/

