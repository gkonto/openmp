#include <iostream>
#include "addarr.hpp"


void add_arrays(double *A, double *B, double *C, size_t size) {
    size_t i = 0;
    #pragma omp target is_device_ptr(A, B, C)
    {
        #pragma omp parallel for
        for (i = 0; i < size; ++i) {
            C[i] = A[i] + B[i];
        }
    }
}
