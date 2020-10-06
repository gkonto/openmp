#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <omp.h>
#include <stdlib.h>
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

static void print_vec(int *a, size_t num) {
	std::cout << "Vec " << std::endl;
	for (int i = 0; i < num; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int *a = new int[o.size];
    int *b = new int[o.size];

    fill_random_arr(a, b, o.size);

    //Count time
    double start = omp_get_wtime();
    int dprod = dot_prod(a, b, o.size);
    double end = omp_get_wtime();

    // Calculating total time taken by the program.
    double time_taken = end - start;
    std::cout << "Execution Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
//    print_vec(a, o.size);
 //   print_vec(b, o.size);
  //  std::cout << dprod << std::endl;

    delete []a;
    delete []b;

    return 0;
}
