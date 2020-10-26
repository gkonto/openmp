#include <omp.h>
#include "integ.hpp"

#define MIN_BLK 1000000

double pi_comp(int Nstart, int Nfinish, double step) {
    double x = 0.0;
    double sum = 0.0, sum1 = 0.0, sum2 = 0.0;

    if (Nfinish - Nstart < MIN_BLK) {
        for (int i = Nstart; i < Nfinish; ++i) {
            x = (i + 0.5) * step;
            sum += 4.0/(1.0 + x*x);
        }
    } else {
        int iblk = Nfinish-Nstart;
#pragma omp task shared(sum1)
        sum1 = pi_comp(Nstart, Nfinish-iblk/2, step);
#pragma omp task shared(sum2)
        sum2 = pi_comp(Nfinish-iblk/2, Nfinish, step);
#pragma omp taskwait
        sum = sum1 + sum2;
    }

    return sum;
}
