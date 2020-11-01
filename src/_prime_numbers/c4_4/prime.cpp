#include "prime.hpp"


/*
 * COMMENT
 * Ta apotelesmata pou vgazei einai polu lathos me to atomic.
 *
 */

int prime_number(int n) {
    int total = 0;
#pragma omp target map(tofrom: total)
#pragma omp teams
#pragma omp parallel for
    for (int i = 2; i <= n; i++) {
	int prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
#pragma omp atomic
        total += prime;
    }

    return total;
}

