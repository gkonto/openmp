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


/*
   PRIME_NUMBER_SWEEP does repeated calls to PRIME_NUMBER.
  Parameters:
    Input, int N_HI, the last value of N.
    each iteration.
*/
static int prime_number_sweep(int n_hi) {
    return prime_number(n_hi);
}


class Logger {
	public:
		Logger() {
			hi();
		}

		~Logger() {
			bye();
		}

	private:
		void hi() {
			timestamp();
			printf("\n");
			printf("prime_TEST\n");
			printf("  C version\n");
			printf("  Test the prime library.\n");
			printf("\n");
			printf("  Call PRIME_NUMBER to count the primes from 1 to N.\n");
			printf("\n");
			printf("         N        Pi          Time\n");
			printf("\n");
		}

		void bye() {
			printf("\n");
			printf("prime_TEST\n");
			printf("  Normal end of execution.\n");
			printf("\n");
			timestamp();
		}
};


// MAIN is the main program for prime_TEST.
int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    Logger l;
    double start = omp_get_wtime();
    int primes = prime_number_sweep(o.max);
    std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds"<< std::endl;
    std::cout << "Prime numbers: " << primes << std::endl;
    return 0;
}
/******************************************************************************/

/******************************************************************************/
