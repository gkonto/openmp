#include "saxpy.hpp"
#include <cstddef>

//TODO implement both with -O0 and -O2.
void saxpy(size_t n, float a, const float *x, float *y) {
    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];
    }
}