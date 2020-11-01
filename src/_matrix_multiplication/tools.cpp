#include <stdlib.h>
#include <iostream>
#include "tools.hpp"


int **create_matrix(int rows, int cols) {
    int **mat = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
    }
    return mat;
}

int *cr_matrix_1d(int rows, int cols) {
	return new int [rows*cols];
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

void fill_random_1d(int *mat, int width, int height) {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; ++col) {
			mat[col + row*width] = rand() % 20 - 10;
		}
	}
}

void fill_random(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < cols; ++k) {
            mat[i][k] = rand() % 20 - 10;
        }
    }
}




void show_matrix(int **m, int d1, int  d2) {
	std::cout << "[" << std::endl;
	for (int i = 0; i < d1; i++) {
		std::cout << "\t";
		for (int j = 0; j < d2; ++j) {
			std::cout << m[i][j]; 
			std::cout << " " ; 
		}
		std::cout << std::endl;
	}
	std::cout << "]" << std::endl;
}

void show_matrix_1d(int *m, int d1, int  d2) {
	std::cout << "[" << std::endl;
	for (int i = 0; i < d1; i++) {
		std::cout << "\t";
		for (int j = 0; j < d2; ++j) {
			std::cout << m[j + d2 * i];
			std::cout << " " ; 
		}
		std::cout << std::endl;
	}
	std::cout << "]" << std::endl;
}



void verify(int **a, int **b, int **c, int d1, int d2, int d3)
{
	show_matrix(a, d1, d2);
	show_matrix(b, d2, d3);
	show_matrix(c, d1, d3);
}

void verify_1d(int *a, int *b, int *c, int d1, int d2, int d3) 
{
	show_matrix_1d(a, d1, d2);
	show_matrix_1d(b, d2, d3);
	show_matrix_1d(c, d1, d3);

	for (int i = 0; i < d1; ++i) {
		for (int j = 0; j < d3; ++j) {
			int temp = 0;
			for (int k = 0; k < d2; ++k) {
				temp += a[k + i * d2] * b[j + k * d3];
			}
			if (c[j + i * d3] != temp) {
				std::cout << "FAILED!!! Wrong results..." << std::endl;
				exit(1);
			}
		}
	}

}
