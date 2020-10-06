#include <iostream>
#include "addarr.hpp"


void double_elements(int *A, size_t size) {
#pragma omp target map(A[:size] )
    for (size_t i = 0; i < size; ++i) {
            A[i] = A[i] * 2;
    }
}
