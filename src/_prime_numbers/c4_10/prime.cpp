#include "prime.hpp"


/*
 * COMMENT
 * Vgazei ena periergo warning.
 * To provlima lunetai me enan paromoio 
 * tropo, sto paradeigma c4_9
 *
 */


int prime_number(int n) {
    int total = 0;
#pragma omp target map(tofrom: total)
#pragma omp teams reduction (+:total)
#pragma omp distribute
    for (int i = 2; i <= n; i++) {
	int prime = 1;
#pragma omp parallel for 
	for (int j = 2; j < i; j++) {
	    if (i % j == 0) {
		prime = 0;
#pragma omp cancel for
		    }
	}
        total += prime;
    }

    return total;
}

