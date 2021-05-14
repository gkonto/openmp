#include <iostream>
#include <math.h>
#include "auxiliaries.hpp"
#include "prod_cons.hpp"
#include <iomanip>
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
    int total = producer_consumer(o.size);
    double end = omp_get_wtime();

    int ver = 0;
    for (int i = 0; i < o.size; i++) {
        ver += i;
    }

    if (ver != total) {
        std::cout << "Failed Verification!" << std::endl;
        std::cout << "Expected: " << ver << " Got: " << total <<  std::endl;
        exit(1);
    }

    std::cout << "Calculation time: " << std::fixed << std::setprecision(3) << end - start << " sec" << std::endl;
    return 0;
}
