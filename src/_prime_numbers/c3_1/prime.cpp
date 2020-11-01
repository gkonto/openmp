#include "prime.hpp"
/*
 * COMMENTS
 * De kanei compile.
 * Thelei na einai ordered to simd
  */
int prime_number(int n) {
    int total = 0;
#pragma omp parallel for simd ordered 
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

