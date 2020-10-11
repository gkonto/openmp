#include "saxpy.hpp"
#include <cstddef>

//TODO compile with -O0 -O2 and std==c++14

void saxpy(size_t n, float a, const float *x, float *y) {
    #pragma omp target map(tofrom: y[0:n]) map(to: x[0:n])
    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i]; 
    }
}
