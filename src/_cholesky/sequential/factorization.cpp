
#include "factorization.hpp"
#include <iostream>
#include <string.h>
#include <cmath>
#include "../matrix.hpp"

double **cholesky(double **A, int n) {
    //double *L = (double*)calloc(n * n, sizeof(double));
    RectMatrix L(n, false);
    //if (L == NULL)
     //   exit(EXIT_FAILURE);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (i+1); j++) {
            double s = 0;
            for (int k = 0; k < j; k++)
                s += L[i][k] * L[j][k];
            L[i][j] = (i == j) ? std::sqrt(A[i][i] - s) :
                           (1.0 / L[j][j] * (A[i][j] - s));
            //if (i == j) {
             //   std::cout << i << " " << L[i][j] << std::endl;
            //}
        }
    }
    std::cout << L[0][0] << std::endl;
    return L.entries();
}

/*
double **cholesky(double **A, int rows) {
    size_t n = rows;
    //double **result = create_matrix(rows, rows);
    RectMatrix result(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 0; k < i; ++k) {
            double value = A[i][k];
            for (size_t j = 0; j < k; ++j)
                value -= result[i][j] * result[k][j];
            result[i][k] = value/result[k][k];
        }
        double value = A[i][i];
        for (size_t j = 0; j < i; ++j)
            value -= result[i][j] * result[i][j];
        result[i][i] = std::sqrt(value);
    }
    return result.entries();
}
*/



/*
double **cholesky(double **A, int rows) {
    size_t n = rows;
    //double **result = create_matrix(rows, rows);
    RectMatrix matrix(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 0; k < i; ++k) {
            double value = A[i][k];
            for (size_t j = 0; j < k; ++j)
                value -= matrix[i][j] * matrix[k][j];
            matrix[i][k] = value/matrix[k][k];
        }
        double value = A[i][i];
        for (size_t j = 0; j < i; ++j)
            value -= matrix[i][j] * matrix[i][j];
        matrix[i][i] = std::sqrt(value);
    }
    return matrix.entries();
}
*/


