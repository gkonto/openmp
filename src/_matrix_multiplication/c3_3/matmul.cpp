#include <iostream>
#include "matmul.hpp"

#define SINGLE_POINTER

#ifdef SINGLE_POINTER
void matmul(int *a, int r1, int c1,
		int *b, int r2, int c2,
		int *c, int r3, int c3)
{
	if (c1 != r2) {
		std::cout << "Wrong matrix dimensions!" << std::endl;
		return;
	}

	int a_size = r1 * c1;
	int b_size = r2 * c2;
	int c_size = r3 * c3;

#pragma omp target map(to: a[0:a_size], b[0: b_size]) map(from: c[0:c_size])
#pragma omp parallel for collapse(2)
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			int temp = 0;
#pragma omp simd reduction(+ : temp)
			for (int k = 0; k < c1; ++k) {
				temp += a[k + i*c1] * b[j + k*c2];
			}

			c[j + i * c3] = temp;
		}
	}
}
#else
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
#endif
