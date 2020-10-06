#include <iostream>
#include "addarr.hpp"


int dot_prod(int *A, int *B, size_t size) {
	int sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (size_t i = 0; i < size; ++i) {
		sum += A[i] * B[i];
	}
	return sum;
}
