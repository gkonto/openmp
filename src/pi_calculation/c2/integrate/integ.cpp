#include <omp.h>
#include "integ.hpp"

//Examplep in p57

static long num_steps = 1000000000;
#define NUM_THREADS 4
#define PAD 8 // assume 64 byte L1 cache line size

double pi() {
    int nthreads = 0;
    double pi = .0, sum[NUM_THREADS][PAD];
    double step= 1.0/(double)num_steps;
    omp_set_num_threads(NUM_THREADS);

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

    for (int i = 0; i < nthreads; ++i)
    {
        pi += sum[i][0] * step;
    }

    return pi;
}
