#include "saxpy.hpp"
#include <cstddef>

//TODO compile with -O0 -O2 and std==c++14

void saxpy(size_t n, float a, const float *x, float *y) {
    #pragma omp target teams distribute parallel for simd is_device_ptr(y, x)
    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i]; 
    }
}
