#include "auxiliaries.hpp"
#include "prime.hpp"
#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


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


static void report_header() {
    printf("\n");
    printf("  Call PRIME_NUMBER to count the primes from 1 to N.\n");
    printf("\n");
    printf("         N        Pi          Time\n");
    printf("\n");
}


/*
   PRIME_NUMBER_SWEEP does repeated calls to PRIME_NUMBER.
  Parameters:
    Input, int N_HI, the last value of N.
    each iteration.
*/
static void prime_number_sweep(int n_hi) {
    report_header();
    double start = omp_get_wtime();
    int primes = prime_number(n_hi);
    double end = omp_get_wtime();
    printf("  %8d  %8d  %14f\n", n_hi, primes, end-start);
}


static void greetings() {
    timestamp();
    printf("\n");
    printf("prime_TEST\n");
    printf("  C version\n");
    printf("  Test the prime library.\n");
}


static void bye() {
    printf("\n");
    printf("prime_TEST\n");
    printf("  Normal end of execution.\n");
    printf("\n");
    timestamp();
}


// MAIN is the main program for prime_TEST.
int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    greetings();
    double start = omp_get_wtime();
    prime_number_sweep(o.max);

    bye();
    std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds"<< std::endl;

    return 0;
}
/******************************************************************************/

/******************************************************************************/

