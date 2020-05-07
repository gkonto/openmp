#include <iostream>
#include <omp.h>
#include "integrate/integ.hpp"

// Example on page 52
static long num_steps = 1000000000;

int main(void) {
    auto seconds = omp_get_wtime();
    double step = 1.0/(double)num_steps;
    double sum = 0.0;
    double p = 0.0;
#pragma omp parallel
    {
#pragma omp single
        sum = pi_comp(0, num_steps, step);
    }
    p = step * sum;

    std::cout << "Value: " << p << std::endl;
    std::cout << omp_get_wtime() - seconds << std::endl;
    if (abs(p - 3.1415) > 0.001) {
        return 1;
    }
    return 0;
}
