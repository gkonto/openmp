#include "integ.hpp"

static long num_steps = 1000000000;

double pi() {
    int upper_limit = 1;
    double step = upper_limit/(double)num_steps;
    double sum = .0;
    double pi = .0;

    for (int i = 0; i < num_steps; ++i)
    {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x*x);
    }
    pi = step * sum;

    return pi;
}
