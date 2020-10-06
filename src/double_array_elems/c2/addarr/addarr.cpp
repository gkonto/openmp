#include <iostream>
#include <omp.h>
#include "addarr.hpp"


void double_elements(int *A, size_t size) {
	int flag = 0;
#pragma omp target map(A[:size], flag)
	{
		if (!omp_is_initial_device()) {
			flag = 1;
		} else {
			flag = 2;
		}
	#pragma omp parallel for
		for (size_t i = 0; i < size; ++i) {
			A[i] = A[i] * 2;
		}
	}

	if (flag == 1) {
		printf("Executed in accelerator\n");
	} else if (flag == 2) { 
		printf("Executed in host\n");
	}
}
