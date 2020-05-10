#include <iostream>
#include <omp.h>
#include <cmath>
#include <sstream>
#include "integrate/integ.hpp"

namespace {
    struct Opts {
        long num_steps = 0;
        int num_threads = 0;
    };
}

template<typename T>
static void read_value(char *val, T &num) {
    std::stringstream ss;
    ss << val;
    ss >> num;
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify number of steps" << std::endl;
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

    std::cout << "pi Value: "<<  p << std::endl;
    if (fabs(p - 3.1415) > 0.01) {
        return 1;
    }
    return 0;
}
