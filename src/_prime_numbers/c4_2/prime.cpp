#include "prime.hpp"

int prime_number(int n) {
    int total = 0;
#pragma omp target map(tofrom: total)
#pragma omp simd reduction(+ : total)
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

