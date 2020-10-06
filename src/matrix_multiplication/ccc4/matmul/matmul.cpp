#include <iostream>
#include "matmul.hpp"


void matmul(int **A, int r1, int c1,
        int **B, int r2, int c2,
        int **&C, int &r3, int &c3) {

    r3 = r1;
    c3 = c2;

#pragma omp target teams distribute parallel for \
    is_device_ptr(A)\
    is_device_ptr(B)\
    is_device_ptr(C)
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
