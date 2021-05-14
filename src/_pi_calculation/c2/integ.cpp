#include <omp.h>
#include <iostream>
#include "integ.hpp"

#define PAD 8 // assume 64 byte L1 cache line size

struct particle
{
	double val;
    double pad[7] = {0.};
};

double pi(long num_steps) {
    double pi = .0;
    int num_threads = 0;
#pragma omp parallel shared(num_threads)
    {
	    int id = omp_get_thread_num();
	    if (id == 0) {
		    num_threads = omp_get_num_threads();
	    }
    }
    particle *sum = new particle[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        sum[i].val = 0.0;
    }

    double step= 1.0/(double)num_steps;

#pragma omp parallel 
    {
        int thread_num = omp_get_thread_num();
        int numthreads = omp_get_num_threads();

	int low = num_steps * thread_num / numthreads;
	int high = num_steps * (thread_num + 1)/ numthreads;

        for (int i = low; i < high; ++i) {
            double x = (i + 0.5)*step;
            sum[thread_num].val += 4.0/(1.0 + x*x);
        }
    }

    for (int i = 0; i < num_threads; ++i) {
        pi += sum[i].val * step;
    }

    delete []sum;
    return pi;
}
