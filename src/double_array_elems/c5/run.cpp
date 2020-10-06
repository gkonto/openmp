#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include "addarr/addarr.hpp"
#include "auxiliaries.hpp"
#include "tools.hpp"


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

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    int device = omp_get_default_device();
    std::cout << "Device: " << device << std::endl;
    int *a = (int *)omp_target_alloc(sizeof(int) * o.size, device);

    if (!a) {
	    std::cout << "Could not allocate memory for array" << std::endl;
	    exit(1);
    } else {
	    std::cout << "Successful allocation" << std::endl;
    }

    std::cout << "Starting initialization" << std::endl;
#pragma omp target is_device_ptr(a)
#pragma omp parallel for
    for (size_t i = 0; i < o.size; ++i) {
	    a[i] = static_cast<int>(i);
    }

    //Count time
    std::cout << "Starting calculation" << std::endl;
    auto start = omp_get_wtime();
    double_elements(a, o.size);
    auto end = omp_get_wtime();

    std::cout << "Starting verification" << std::endl;
#pragma omp target is_device_ptr(a)
#pragma omp parallel for
    for (size_t i = 0; i < o.size; ++i) {
	    if (a[i] != i * 2) {
		    exit(1);
	    }
    }

    std::cout << "Successful verification" << std::endl;
    omp_target_free(a, device);

    // Calculating total time taken by the program.
    std::cout << "Execution Time : " << std::fixed
         << end - start << std::setprecision(5);
    std::cout << " sec " << std::endl;

    return 0;
}
