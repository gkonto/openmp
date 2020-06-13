#include <iostream>
#include <omp.h>
#include <memory>
#include "auxiliaries.hpp"

//TODO THere is a data race in this. 
//Find it.
struct Opts {
    size_t arr_size_ = 0;
    int num_threads_ = 1;
};

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Please provide array size and num threads" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.arr_size_);
    read_value<int>(argv[2], o.num_threads_);
}

int main(int argc, char **argv) {
    double sum  = 0.0;
    int flag = 0;
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    omp_set_num_threads(o.num_threads_);

    unsigned char *arr = new unsigned char [o.arr_size_];
    double runtime = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            initialize_rand_arr(arr, o.arr_size_);
#pragma omp flush
            flag = 1;
#pragma omp flush(flag)
        }
#pragma omp section
        {
#pragma omp flush(flag)
            while (flag == 0) {
#pragma omp flush(flag)
            }
#pragma omp flush
            sum = accumulate(arr, o.arr_size_);
        }
    }
    delete []arr;

    runtime = omp_get_wtime() - runtime;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Elapsed Time: " << runtime << std::endl;
}

