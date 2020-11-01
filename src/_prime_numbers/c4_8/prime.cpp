#include "prime.hpp"


/*
 * COMMENT
 * De mporei na kanei compile giati 
 * de mporei kaneis na xrisimopoieisai parallel for 
 * me break.
 *
 */


int prime_number(int n) {
    int total = 0;
#pragma omp target map(tofrom: total)
#pragma omp teams reduction (+:total)
#pragma omp distribute parallel for simd
    for (int i = 2; i <= n; i++) {
	int prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        total += prime;
    }

    return total;
}

