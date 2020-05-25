#include <stdlib.h>
#include "tools.hpp"

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


