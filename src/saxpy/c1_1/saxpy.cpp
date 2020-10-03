#include "saxpy.hpp"
#include <cstddef>


void saxpy(size_t n, float a, const float64 *x, float64 *y) {
    #pragma omp parallel for 
    for (size_t i = 0; i < n; ++i) {
        y[i].v_ = a * x[i].v_ + y[i].v_;
    }
}