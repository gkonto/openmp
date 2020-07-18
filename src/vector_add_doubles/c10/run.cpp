#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include "addarr/addarr.hpp"
#include "auxiliaries.hpp"


namespace {
    struct Opts{
        size_t size = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify array size!" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.size);
}

static void fill_random_arr(double *arr, size_t size) {
    #pragma omp target is_device_ptr(arr)
    for (int i = 0; i < size; i++) {
        arr[i] = double(rand() % 100 + 1);
    }
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));

    int dev = omp_get_default_device();
    double *a_dev = (double *)omp_target_alloc(sizeof(double) * o.size, dev);
    double *b_dev = (double *)omp_target_alloc(sizeof(double) * o.size, dev);

    fill_random_arr(a_dev, o.size);
    fill_random_arr(b_dev, o.size);

    double *c_dev = (double *)omp_target_alloc(sizeof(double) * o.size, dev);

    //Count time
    auto start = omp_get_wtime();
    add_arrays(a_dev, b_dev, c_dev, o.size);
    auto end = omp_get_wtime();

    // Calculating total time taken by the program.
    std::cout << "Execution Time : " << std::fixed
         << end - start << std::setprecision(5);
    std::cout << " sec " << std::endl;

    delete []a_dev;
    delete []b_dev;
    delete []c_dev;

    return 0;
}
