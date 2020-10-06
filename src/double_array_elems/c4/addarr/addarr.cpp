#include <iostream>
#include <omp.h>
#include "addarr.hpp"


void double_elements(int *A, size_t size) {
	int flag = 0;
#pragma omp target parallel for simd map(A[:size], flag)
		for (size_t i = 0; i < size; ++i) {
			A[i] = A[i] * 2;
		}

	if (flag == 1) {
		printf("Executed in accelerator\n");
	} else if (flag == 2) { 
		printf("Executed in host\n");
	}
}
