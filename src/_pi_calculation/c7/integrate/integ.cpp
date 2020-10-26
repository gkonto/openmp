#include <omp.h>
#include "integ.hpp"
#include <iostream>

double pi(long num_steps) {
    double dH = 1.0/(double)num_steps;
    double dX = 0.0, dSum = 0.0;

#pragma omp target teams distribute map(tofrom: dSum),\
   				    map(to:dX,  dH, num_steps)\
    				    reduction(+:dSum)
    for (int i = 0; i < num_steps; i++) {
	dX = dH * ((double) i  + 0.5);
	dSum += (4.0 / (1.0 + dX * dX));
    } // End parallel for simd region

    return dH * dSum;
}

