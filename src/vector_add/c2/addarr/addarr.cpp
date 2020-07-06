#include <iostream>
#include "addarr.hpp"


void add_arrays(short *A, short *B, short *C, size_t size) {
#pragma omp parallel for
    for (size_t i = 0; i < size; ++i) {
            C[i] = A[i] + B[i];
    }
}
