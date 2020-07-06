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
        int num_threads = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify array size and number of threads!" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.size);
    read_value<int>(argv[2], o.num_threads);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    omp_set_num_threads(o.num_threads);

    srand(time(nullptr));
    double *a = new double[o.size];
    double *b = new double[o.size];

    fill_random_arr(a, o.size);
    fill_random_arr(b, o.size);

    double *c = new double[o.size];

    //Count time
    auto start = omp_get_wtime();
    add_arrays(a, b, c, o.size);
    auto end = omp_get_wtime();

    // Calculating total time taken by the program.
    std::cout << "Execution Time : " << std::fixed
         << end - start << std::setprecision(5);
    std::cout << " sec " << std::endl;

    delete []a;
    delete []b;
    delete []c;

    return 0;
}
