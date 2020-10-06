#include <iostream>
#include <omp.h>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "matmul/matmul.hpp"
#include "tools.hpp"
#include "auxiliaries.hpp"

namespace {
    struct Opts{
        int dim1 = 0;
        int dim2 = 0;
        int dim3 = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 4) {
        std::cout << "Need 4 arguments! 3 matrix dimensions and the number of threads!" << std::endl;
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
    auto seconds = omp_get_wtime();

#pragma omp parallel
    {
        //FIXME maybe mistake in this single
#pragma omp single
        matmultrec(0, o.dim1, 0, o.dim3, 0, o.dim2, A, B, C);
    }
    seconds = omp_get_wtime() - seconds;
    std::cout << seconds << std::endl;

    destroy_matrix(A, o.dim1);
    destroy_matrix(B, o.dim2);
    destroy_matrix(C, r3);

    return 0;
}
