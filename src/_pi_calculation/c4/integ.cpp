#include <omp.h>
#include "integ.hpp"

double pi(long num_steps) {
    double pi = .0;
    double step= 1.0/(double)num_steps;
    double sum = 0.0;

#pragma omp parallel
    {
        double x = 0.0;

#pragma omp for reduction(+:sum)
        for (int i = 0; i < num_steps; i++) {
            x = (i + 0.5)*step;
            sum += 4.0/(1.0 + x*x);
        }
    }
    pi = step * sum;

    return pi;
}
