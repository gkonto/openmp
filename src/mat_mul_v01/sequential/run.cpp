#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "addarr/addarr.hpp"
#include "auxiliaries.hpp"
#include "tools.hpp"

namespace {
    struct Opts{
	    int d1 = 0;
	    int d2 = 0;
	    int d3 = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 4) {
        std::cout << "Specify three matrix dimensions!" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.size);
    read_value<size_t>(argv[2], o.size);
    read_value<size_t>(argv[3], o.size);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int *a = new int[o.size];

    fill_array(a, o.size);

    //Count time
    clock_t start = clock();
    double_elements(a, o.size);
    clock_t end = clock();

    verify(a, o.size);

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    delete []a;

    return 0;
}