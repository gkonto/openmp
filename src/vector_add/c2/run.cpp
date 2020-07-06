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
    short *a = new short[o.size];
    short *b = new short[o.size];

    fill_random_arr(a, o.size);
    fill_random_arr(b, o.size);

    short *c = new short[o.size];

    //Count time
    clock_t start = clock();
    add_arrays(a, b, c, o.size);
    clock_t end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    delete []a;
    delete []b;
    delete []c;

    return 0;
}
