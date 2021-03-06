#include <iostream>
#include <omp.h>
#include <cmath>
#include <sstream>
#include "integrate/integ.hpp"
#include "auxiliaries.hpp"

namespace {
    struct Opts {
        long num_steps = 0;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify number of steps and num of threads" << std::endl;
        exit(1);
    }

    read_value<long>(argv[1], o.num_steps);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    auto seconds = omp_get_wtime();
    double step = 1.0/(double)o.num_steps;
    double sum = 0.0;
    double p = 0.0;
#pragma omp parallel
    {
#pragma omp single
        sum = pi_comp(0, o.num_steps, step);
    }
    p = step * sum;

    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl;
    std::cout << "pi Value: " << p << std::endl;
    return 0;
}
