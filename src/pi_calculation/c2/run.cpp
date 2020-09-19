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
        std::cout << "Specify number of steps" << std::endl;
        exit(1);
    }

    read_value<long>(argv[1], o.num_steps);
}


int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    auto seconds = omp_get_wtime();
    double p = pi(o.num_steps);
    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl;
    std::cout << "pi Value: "<<  p << std::endl;
    return 0;
}
