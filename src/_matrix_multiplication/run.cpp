#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "matmul.hpp"
#include "auxiliaries.hpp"
#include "tools.hpp"

namespace {
    struct Opts{
        int dim1 = 0;
        int dim2 = 0;
        int dim3 = 0;
	bool verify = false;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc < 4) {
        std::cout << "Specify three dimensions for matrix mult!" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.dim1);
    read_value<int>(argv[2], o.dim2);
    read_value<int>(argv[3], o.dim3);
    if (argc == 5) {
	    read_value<bool>(argv[4], o.verify);
    }
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int *A = new int [o.dim1 * o.dim2];
    int *B = new int [o.dim2 * o.dim3];

    fill_random_1d(A, o.dim1, o.dim2);
    fill_random_1d(B, o.dim2, o.dim3);

    int r3 = o.dim1;
    int c3 = o.dim3;

    clock_t start = clock();
    int *C = new int [r3 * c3];
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Allocation Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    //Count time
    start = clock();
    matmul(A, o.dim1, o.dim2, B, o.dim2, o.dim3, C, r3, c3);
    end = clock();


    // Calculating total time taken by the program.
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Multiplication Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    // Verification
    if (o.verify) {
	    verify_1d(A, B, C, o.dim1, o.dim2, o.dim3);
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
