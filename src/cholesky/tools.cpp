#include <stdlib.h>
#include "tools.hpp"

double **create_matrix(int rows, int cols) {
    double **mat = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new double[cols];
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

void fill_random_symmetric(double **mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < cols; ++k) {
            if (k < i) continue;
            double num = rand() % 10 + 1;
            mat[i][k] = num;
            mat[k][i] = num;
        }
    }
}


