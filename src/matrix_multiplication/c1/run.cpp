#include <iostream>
#include <omp.h>
#include <bits/stdc++.h> 
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "matmul/matmul.hpp"

int **create_matrix(int rows, int cols) {
    int **mat = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
    }
    return mat;
}


void destroy_matrix(int **&mat, int rows) {
    if (mat) {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        mat = nullptr;
    }
}

void fill_random(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < cols; ++k) {
            mat[i][k] = rand() % 100 + 1;
        }
    }
}

namespace {
    struct Opts{
        int dim1 = 0;
        int dim2 = 0;
        int dim3 = 0;
        int threads_num = 0;
    };
}

void read_int(char *arg, int &dim) {
    std::stringstream ss;
    ss << arg;
    ss >> dim;
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 5) {
        std::cout << "Need 4 arguments! 3 matrix dimensions and the number of threads!" << std::endl;
        exit(1);
    }

    read_int(argv[1], o.dim1);
    read_int(argv[2], o.dim2);
    read_int(argv[3], o.dim3);
    read_int(argv[4], o.threads_num);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    omp_set_num_threads(o.threads_num);

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
    matmul(A, o.dim1, o.dim2, B, o.dim2, o.dim3, C, r3, c3);
    seconds = omp_get_wtime() - seconds;
    std::cout << seconds << std::endl;

    destroy_matrix(A, o.dim1);
    destroy_matrix(B, o.dim2);
    destroy_matrix(C, r3);

    return 0;
}
