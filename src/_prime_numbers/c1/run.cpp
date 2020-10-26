#include "auxiliaries.hpp"
#include "prime.hpp"
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

namespace {
    struct Opts {
      int num_threads_;
      int max_;
    };
} // namespace


static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify max boundary and thread number" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.max_);
    read_value<int>(argv[2], o.num_threads_);
}


static void report_header() {
    printf("\n");
    printf("  Call PRIME_NUMBER to count the primes from 1 to N.\n");
    printf("\n");
    printf("         N        Pi \n");
    printf("\n");
}

/*
  Purpose:
   PRIME_NUMBER_SWEEP does repeated calls to PRIME_NUMBER.
    Input, int N_HI, the last value of N.
*/
static void prime_number_sweep(int n_hi) {
    report_header();
    int primes = prime_number(n_hi);
    printf("  %8d  %8d \n", n_hi, primes);
}

static void greetings() {
    printf("\n");
    printf("PRIME_OPENMP\n");
    printf("  C/OpenMP version\n");

    printf("\n");
    printf("  Number of processors available = %d\n", omp_get_num_procs());
    printf("  Number of threads =              %d\n", omp_get_max_threads());
}


int main(int argc, char *argv[]) {
  Opts o;
  parseArgs(argc, argv, o);

  omp_set_num_threads(o.num_threads_);
  greetings();

  double start = omp_get_wtime();
  prime_number_sweep(o.max_);
  std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds"
            << std::endl;
  return 0;
}
