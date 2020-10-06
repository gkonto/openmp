#include <iostream>
#include <omp.h>
#include "addarr.hpp"


void double_elements(int *A, size_t size) {
	int flag = 0;
#pragma omp target teams distribute map(A[:size], flag)
	for (size_t i = 0; i < size; ++i) {
		A[i] = A[i] * 2;
	}
}
