#include <omp.h>
#include "integ.hpp"
#include <iostream>

double pi(long num_steps, int num_threads) {
    double dH = 1.0/(double)num_steps;
    double dX, dSum = 0.0;
    omp_set_num_threads(num_threads);

#pragma omp parallel for simd private(dX) \
    reduction(+:dSum) schedule(simd:static)
    for (int i = 0; i < num_steps; i++) {
        dX = dH * ((double) i  + 0.5);
        dSum += (4.0 / (1.0 + dX * dX));
    } // End parallel for simd region

    return dH * dSum;   
}

