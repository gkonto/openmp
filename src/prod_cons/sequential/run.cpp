#include <iostream>
#include <omp.h>
#include <memory>
#include "auxiliaries.hpp"

struct Opts {
    size_t arr_size_ = 0;
};

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Please provide array size" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.arr_size_);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    double runtime = 0.0;
    srand(time(nullptr));

    unsigned char *arr = new unsigned char [o.arr_size_];
    runtime = omp_get_wtime();
    initialize_rand_arr(arr, o.arr_size_); // Producer: fill an array of data

    long long int sum = accumulate(arr, o.arr_size_); // Consumer: sum the array
    runtime = omp_get_wtime() - runtime;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Elapsed Time: " << runtime << std::endl;

    return 0;
}
