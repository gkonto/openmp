#include "saxpy.hpp"
#include <cstddef>

//TODO compile with -O0 -O2 and std==c++14


#pragma omp declare simd uniform(a) notinbranch
float do_work(float a, float b, float c)
{
    return a * b + c;
}

void saxpy(size_t n, float a, const float *x, float *y) {
    #pragma omp simd 
    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i]; //TODO
    }
}