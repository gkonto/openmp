#include <iostream>
#include <omp.h>
#include <sstream>
#include "fib/fib.hpp"
#include "auxiliaries.hpp"

namespace {
struct Args {
    int value_ = 0;
    int num_of_threads_ = 1;
};
}

static void parseArgs(int argc, char **argv, Args *args) {
    if (argc != 3) {
        std::cout << "Error: 2 arguments must be specified!" << std::endl;
        std::cout << "1: Value to be calculated by fibonacci function - Integer" << std::endl;
        std::cout << "2: Number of threads - Integer" << std::endl;
        exit(1);
    }
    
    read_value<int>(argv[1], args->value_);
    read_value<int>(argv[2], args->num_of_threads_);
}


int main(int argc, char **argv) {
    Args args;
    parseArgs(argc, argv, &args);
    omp_set_num_threads(args.num_of_threads_);
    double time = omp_get_wtime();
    int value = 0;
    #pragma omp parallel 
    {
        //FIXME auto prepei na lathos. Exo single kai mesa sto recursion trexo tasks
        #pragma omp single
            value = fib(args.value_);
    }
    time = omp_get_wtime() - time;

    std::cout << "Value: " << value << std::endl;
    std::cout << "Time: " << time << std::endl;
}
