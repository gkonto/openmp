#include <iostream>
#include "matmul.hpp"


void matmul(int **A, int r1, int c1,
        int **B, int r2, int c2,
        int **&C, int &r3, int &c3) {
    if (c1 != r2) {
        std::cout << "Wrong matrix dimensions!" << std::endl;
        return;
    }

    r3 = r1;
    c3 = c2;

    C = new int*[r1];
    for (int i = 0; i < r1; ++i) {
        C[i] = new int[c2];
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
