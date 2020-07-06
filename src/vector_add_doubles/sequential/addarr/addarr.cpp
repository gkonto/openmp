#include <iostream>
#include "addarr.hpp"


void add_arrays(double *A, double *B, double *C, size_t size) {
    for (size_t i = 0; i < size; ++i) {
            C[i] = A[i] + B[i];
    }
}
