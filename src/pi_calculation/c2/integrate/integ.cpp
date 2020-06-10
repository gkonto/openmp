#include <omp.h>
#include "integ.hpp"

#define PAD 8 // assume 64 byte L1 cache line size

double pi(long num_steps, int num_threads) {
    int nthreads = 0;
    double pi = .0;
    double **sum = new double *[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        sum[i] = new double[PAD];
    }

    double step= 1.0/(double)num_steps;
    omp_set_num_threads(num_threads);

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();

        if (id == 0) {
            nthreads = nthrds;
        }

        for (int i = id; i < num_steps; i += nthrds) {
            double x = (i + 0.5)*step;
            sum[id][0] += 4.0/(1.0 + x*x);
        }
    }

    for (int i = 0; i < nthreads; ++i) {
        pi += sum[i][0] * step;
    }

    delete []sum;
    return pi;
}
