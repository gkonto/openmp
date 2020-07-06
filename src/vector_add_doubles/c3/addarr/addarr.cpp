#include <iostream>
#include "addarr.hpp"

#pragma omp declare simd
double sum(double a, double b) {
    return a + b;
}

void add_arrays(double *A, double *B, double *C, size_t size) {
    size_t i = 0;
#pragma omp parallel for
    for (i = 0; i < size; ++i) {
            C[i] = sum(A[i], B[i]);
    }
}
