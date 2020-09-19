#include <iostream>
#include <stdio.h>
#include <omp.h>
#include "addarr.hpp"


void add_arrays(double *A, double *B, double *C, size_t size) {
    size_t i = 0;
    int flag = 0;
    #pragma omp target map(A, B, C, flag)
    {
	    if (!omp_is_initial_device()) {
		    flag = 1;
	    } else {
		    flag = 2;
	    }
        #pragma omp parallel for
        for (i = 0; i < size; ++i) {
            C[i] = A[i] + B[i];
        }
    }
    if (flag == 1) { 
	    std::cout << "Running on accelerator" << std::endl;
    } else if (flag == 2) {
	    std::cout << "Running on host" << std::endl;
    }
}
