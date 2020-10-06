#include <iostream>
#include "matmul.hpp"

void matmul_1d(int *a, int r1, int c1,
		int *b, int r2, int c2,
		int *c, int r3, int c3)
{
	if (c1  == c2 && c1 == r1 && c1 == r2 && c1 == r3 && c1 == c3) {
		std::cout << "Matrix must be rectangular for this impl!" << std::endl;
		return;
	}

	int a_size = r1 * c1;
	int b_size = r2 * c2;
	int c_size = r3 * c3;

#pragma omp target teams distribute parallel for simd map(a[:a_size], b[:b_size], c[:c_size])
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			int temp = 0;
			for (int k = 0; k < c1; ++k) {
				temp += a[k + i*c1] * b[j + k*c2];
			}

			c[j + i * c3] = temp;
		}
	}
}

void matmul(int **A, int r1, int c1,
        int **B, int r2, int c2,
        int **&C, int &r3, int &c3) {
    if (c1 != r2) {
        std::cout << "Wrong matrix dimensions!" << std::endl;
        return;
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            int tmp = 0;
            for (int k = 0; k < c1; ++k) {
                tmp += A[i][k] * B[k][j];
            }
            C[i][j] = tmp;
        }
    }
}
