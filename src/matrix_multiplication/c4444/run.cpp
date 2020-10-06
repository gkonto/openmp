#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <omp.h>
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

static void fill_random_par(int *mat, int rows, int cols) {
#pragma omp target parallel for is_device_ptr(mat)
	for (int i = 0; i < rows; ++i) {
		for (int k = 0; k < cols; ++k) {
			mat[k + i * cols] = rand() % 20 - 10;
		}
	}
}



int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int device = omp_get_default_device();
    int *A = (int *)omp_target_alloc(sizeof(int *) * o.dim1 * o.dim2, device);
    int *B = (int *)omp_target_alloc(sizeof(int *) * o.dim2 * o.dim3, device);

    fill_random_par(A, o.dim1, o.dim2);
    fill_random_par(B, o.dim2, o.dim3);

    int r3 = o.dim1;
    int c3 = o.dim3;

    clock_t start = clock();
    int *C = (int *)omp_target_alloc(sizeof(int *) * o.dim1 * o.dim2, device);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Allocation Time : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    //Count time
    auto seconds = omp_get_wtime();
    matmul_1d(A, o.dim1, o.dim2, B, o.dim2, o.dim3, C, r3, c3);
    seconds = omp_get_wtime() - seconds;


    // Calculating total time taken by the program.
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Multiplication Time : " << std::fixed
         << seconds << std::setprecision(5);
    std::cout << " sec " << std::endl;

    // Verification
//    verify_1d(A, B, C, o.dim1, o.dim2, o.dim3);

    omp_target_free(A, device);
    omp_target_free(B, device);
    omp_target_free(C, device);

    return 0;
}
