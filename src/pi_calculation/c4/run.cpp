#include <iostream>
#include <sstream>
#include <cmath>
#include <omp.h>
#include "integrate/integ.hpp"
#include "auxiliaries.hpp"

// Example on page 52

namespace {
    struct Opts {
        long num_steps = 0;
        int num_threads = 0;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify number of steps and num of threads" << std::endl;
        exit(1);
    }

    read_value<long>(argv[1], o.num_steps);
    read_value<int>(argv[2], o.num_threads);
}



int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    auto seconds = omp_get_wtime();
    double p = pi(o.num_steps, o.num_threads);
    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl;
    std::cout << "pi Value: " << p << std::endl;
    return 0;
}
