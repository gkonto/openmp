#include <iostream>
#include <sstream>
#include <omp.h>
#include "fib/fib.hpp"
#include "auxiliaries.hpp"

static int parseArgs(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Specify fibonacci value to be calculated" << std::endl;
        exit(1);
    }
    
    int val = 0;
    read_value<int>(argv[1], val);

    return val;
}

int main(int argc, char **argv) {
    int val = parseArgs(argc, argv);

    double time = omp_get_wtime();
    int value = fib(val);
    time = omp_get_wtime() - time;

    std::cout << "Time Elapsed: " << time << std::endl;
    std::cout << "Value: " << value << std::endl;
    return 0;
}
