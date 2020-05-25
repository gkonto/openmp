#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "matmul/matmul.hpp"
#include "auxiliaries.hpp"
#include "tools.hpp"

namespace {
    struct Opts{
        int dim1 = 0;
        int dim2 = 0;
        int dim3 = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 4) {
        std::cout << "Specify three dimensions for matrix mult!" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.dim1);
    read_value<int>(argv[2], o.dim2);
    read_value<int>(argv[3], o.dim3);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int **A = create_matrix(o.dim1, o.dim2);
    int **B = create_matrix(o.dim2, o.dim3);

    fill_random(A, o.dim1, o.dim2);
    fill_random(B, o.dim2, o.dim3);

    int r3 = o.dim1;
    int c3 = o.dim3;
    int **C = nullptr;

    C = new int*[r3];
    for (int i = 0; i < r3; ++i) {
        C[i] = new int[c3];
    }

    //Count time
    clock_t start = clock();
    matmul(A, o.dim1, o.dim2, B, o.dim2, o.dim3, C, r3, c3);
    clock_t end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Multiplication Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    destroy_matrix(A, o.dim1);
    destroy_matrix(B, o.dim2);
    destroy_matrix(C, r3);

    return 0;
}
