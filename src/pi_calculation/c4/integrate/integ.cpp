#include <omp.h>
#include "integ.hpp"


//Example at p72
static long num_steps = 1000000000;
#define NUM_THREADS 2

double pi() {
    int nthreads = 0;
    double pi = .0;
    double step= 1.0/(double)num_steps;
    omp_set_num_threads(NUM_THREADS);


#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        double sum = 0.0;

        if (id == 0) {
            nthreads = nthrds;
        }

        for (int i = id, sum = 0.0; i < num_steps; i += nthreads) {
            double x = (i + 0.5)*step;
            sum += 4.0/(1.0 + x*x);
        }
        sum *= step;
#pragma atomic
        pi += sum;
    }

    return pi;
}
