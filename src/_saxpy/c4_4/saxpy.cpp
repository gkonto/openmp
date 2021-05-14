#include "saxpy.hpp"
#include <cstddef>
#include <iostream>
#include <omp.h>

//TODO compile with -O0 -O2 and std==c++14

void saxpy(size_t n, float a, const float *x, float *y) {
    int isinitial = 0;
    #pragma omp target map(tofrom: isinitial) is_device_ptr(y, x)
    {

        if (omp_is_initial_device()) isinitial = 1;
    #pragma omp teams distribute parallel for simd 
        for (size_t i = 0; i < n; ++i) {
            y[i] = a * x[i] + y[i]; 
        }
    }

    std::cout << isinitial << std::endl;
}
