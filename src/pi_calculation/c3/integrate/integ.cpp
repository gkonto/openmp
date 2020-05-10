#include <omp.h>
#include <iostream>
#include "integ.hpp"


//Example at p71
double pi(long num_steps, int num_threads) {
    int nthreads = 0;
    double pi = .0;

    double step= 1.0/(double)num_steps;
    omp_set_num_threads(num_threads);

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        double sum = 0.0, x = 0.0;

        if (id == 0) {
            nthreads = nthrds;
        }

        for (int i = id;  i < num_steps; i += nthreads) {
            x = (i + 0.5)*step;
            sum += 4.0/(1.0 + x*x);
        }
#pragma omp critical
        pi += sum * step;
    }

    return pi;
}
