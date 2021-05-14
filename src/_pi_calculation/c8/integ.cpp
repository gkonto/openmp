#include <omp.h>
#include "integ.hpp"

double pi(long num_steps) {
    double pi = .0;
    double step= 1.0/(double)num_steps;
    double sum = 0.0;

#pragma omp parallel firstprivate(sum) shared(pi)
    {
        double x = 0.0;

#pragma omp for 
        for (int i = 0; i < num_steps; i++) {
            x = (i + 0.5)*step;
            sum += 4.0/(1.0 + x*x);
        }

#pragma omp  atomic//critical
        pi += step * sum;
    }

    return pi;
}
