#include <omp.h>
#include "integ.hpp"

double pi(long num_steps) {
    double pi = .0;
    double step= 1.0/(double)num_steps;

#pragma omp parallel shared(pi)
    {
        double x = 0.0;

#pragma omp for 
        for (int i = 0; i < num_steps; i++) {
            x = (i + 0.5)*step;
#pragma omp atomic
            pi += step * 4.0/(1.0 + x*x);
        }
    }

    return pi;
}
