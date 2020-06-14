#include <iostream>
#include <omp.h>
#include <vector>
#include "auxiliaries.hpp"

struct Opts {
    size_t factorial_ = 0;
};

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify integer to be accumulated" << std::endl;
        exit(1);
    }
    read_value<size_t>(argv[1], o.factorial_);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    long long int fact = 0;
    double start = omp_get_wtime();

#pragma omp simd reduction(+:fact)
    for (size_t i = 0; i < o.factorial_ + 1; i++) {
        fact += i;
    }

    double end = omp_get_wtime();
    std::cout << "Result: " << fact << std::endl;

    std::cout << "Time Elapsed: " << end - start << std::endl;
    return 0;
}
