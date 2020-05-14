#include <iostream>
#include <cmath>
#include <omp.h>
#include "integrate/integ.hpp"
#include <sstream>

namespace {
    struct Opts {
        long num_steps = 0;
    };
}

static void read_long_value(char *val, long &num) {
    std::stringstream ss;
    ss << val;
    ss >> num;
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify number of steps" << std::endl;
        exit(1);
    }

    read_long_value(argv[1], o.num_steps);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    auto seconds = omp_get_wtime();
    double p = pi(o.num_steps);
    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl;
    std::cout << "pi Value: " << p << std::endl;
    return 0;
}
