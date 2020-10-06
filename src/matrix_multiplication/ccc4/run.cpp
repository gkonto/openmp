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


static void fill_random_par(int **mat, int rows, int cols) {
#pragma omp target parallel for is_device_ptr(mat)
	for (int i = 0; i < rows; ++i) {
		for (int k = 0; k < cols; ++k) {
			mat[i][k] = rand() % 20 - 10;
		}
	}
}

static int **create_matrix_par(int d1, int d2, int device) {
	int **mat = (int **)omp_target_alloc(sizeof(int *) * d1, device);
#pragma omp target parallel for is_device_ptr(mat)
	for (int i = 0; i < d1; ++i) {
		mat[i] = (int *)malloc(sizeof(int) * d2);
		//mat[i] = (int *)omp_target_alloc(sizeof(int) * d2, device);
	}

	return mat;
}

static void destroy_matrix_par(int **mat, int rows, int device) {
	if (mat) {
#pragma omp target parallel for is_device_ptr(mat)
		for (int i = 0; i < rows; ++i) {
			free(mat[i]);
			//omp_target_free(mat[i], device);
		}
		omp_target_free(mat, device);
	}
}


int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    int device = omp_get_default_device();
    std::cout << "Allocating matrix A" << std::endl;
    int **A = create_matrix_par(o.dim1, o.dim2, device);
    std::cout << "Allocating matrix B" << std::endl;
    int **B = create_matrix_par(o.dim2, o.dim3, device);
    if (!A) {
	    std::cout << "Could not allocate memory for matrix A" << std::endl;
	    exit(1);
    } 

    if (!B) {
	    std::cout << "Could not allocate memory for matrix B" << std::endl;
	    exit(1);
    } 
    std::cout << "Filling matrix A" << std::endl;
    fill_random_par(A, o.dim1, o.dim2);
    std::cout << "Filling matrix B" << std::endl;
    fill_random_par(B, o.dim2, o.dim3);

    int r3 = o.dim1;
    int c3 = o.dim3;
    std::cout << "Device: " << device << std::endl;

    int **C = create_matrix_par(r3, c3, device);

    if (!C) {
	    std::cout << "Could not allocate memory for matrix C" << std::endl;
	    exit(1);
    }

    //Count time
    std::cout << "Starting calculation" << std::endl;
    auto seconds = omp_get_wtime();
    matmul(A, o.dim1, o.dim2, B, o.dim2, o.dim3, C, r3, c3);
    seconds = omp_get_wtime() - seconds;
    std::cout << seconds << std::endl;

    //verify(A, B, C, o.dim1, o.dim2, o.dim3);
    std::cout << "Finishing" << std::endl;

    destroy_matrix_par(A, o.dim1, device);
    destroy_matrix_par(B, o.dim2, device);
    destroy_matrix_par(C, r3, device);

    return 0;
}
