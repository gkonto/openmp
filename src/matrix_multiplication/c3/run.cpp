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
        int N = 0;
        int BS = 0;
        int threads_num = 0;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 4) {
        std::cout << "Need 3 arguments!" << std::endl;
        std::cout << "1: Rectangular matrix size!" << std::endl;
        std::cout << "2: Rectangular submatrix!" << std::endl;
        std::cout << "3: Number of threads" << std::endl;
        exit(1);
    }



    read_value<int>(argv[1], o.N);
    read_value<int>(argv[2], o.BS);
    read_value<int>(argv[3], o.threads_num);

    if (o.N < o.BS) {
        std::cout << "N must be bigger than BS" << std::endl;
        exit(1);
    }

    if (o.N % o.BS != 0) {
        std::cout << "BS must divide N perfectly!" << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    omp_set_num_threads(o.threads_num);

    srand(time(nullptr));
    int **A = create_matrix(o.N, o.N);
    int **B = create_matrix(o.N, o.N);

    fill_random(A, o.N, o.N);
    fill_random(B, o.N, o.N);

    int r3 = o.N;
    int c3 = o.N;
    int **C = nullptr;

    C = new int*[r3];
    for (int i = 0; i < r3; ++i) {
        C[i] = new int[c3];
    }

    //Count time
    auto seconds = omp_get_wtime();
#pragma omp parallel
    {
    #pragma omp single
        matmul( o.N, o.BS, A, B, C );
    }
    seconds = omp_get_wtime() - seconds;
    std::cout << seconds << std::endl;

    destroy_matrix(A, o.N);
    destroy_matrix(B, o.N);
    destroy_matrix(C, r3);

    return 0;
}
