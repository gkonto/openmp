#include <iostream>
#include <omp.h>
#include <sstream>
#include "fib/fib.hpp"

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
    
    char *v = argv[1];
    std::stringstream ss;
    ss << v;
    ss >> args->value_;

    v = argv[2];
    std::stringstream ss1;
    ss1 << v;
    ss1 >> args->num_of_threads_;
}


int main(int argc, char **argv) {
    Args args;
    parseArgs(argc, argv, &args);
    omp_set_num_threads(args.num_of_threads_);
    #pragma omp parallel 
    {
        #pragma omp single
             std::cout << fib(args.value_) << std::endl;
    }
}
