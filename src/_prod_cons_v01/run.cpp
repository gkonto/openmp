#include <iostream>
#include <math.h>
#include "auxiliaries.hpp"
#include "prod_cons.hpp"
#include <omp.h>

namespace {
    struct Opts {
        int size = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o)
{
    if (argc != 2) {
        std::cout << "Specify number of elements" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.size);
}


int main(int argc, char **argv)
{
    Opts o;
    parseArgs(argc, argv, o);

    double start = omp_get_wtime();
    producer_consumer(o.size);
    double end = omp_get_wtime();

    double time_taken = end - start;
    std::cout << "Calculation time: " << time_taken << " sec" << std::endl;
    return 0;
}
