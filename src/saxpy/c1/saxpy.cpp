#include "saxpy.hpp"
#include <cstddef>

void saxpy(size_t n, float a, const float *x, float *y) {
    #pragma omp parallel for 
    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];
    }
}