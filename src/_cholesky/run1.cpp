#include <cassert>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include "omp.h"
#include "matrix.hpp"
#include "auxiliaries.hpp"



void print(std::ostream& out, double **a, int rows, int cols) {
    size_t columns = cols;
    out << std::fixed << std::setprecision(5);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            if (column > 0)
                out << ' ';
            out << std::setw(9) << a[row][column];
        }
        out << '\n';
    }
}

 
static void print_cholesky_factor(double **A, int rows, int cols) {
    std::cout << "Matrix:\n";
    print(std::cout, A, rows, cols);
    std::cout << "Cholesky factor:\n";
    print(std::cout, cholesky(A, rows, cols), rows, cols);
}


 
int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    RectMatrixParser p(o.input_);
    RectMatrix *mat = p.build();
    double start = omp_get_wtime();
    int mat_size = mat->size();
    double **result = cholesky(mat->entries(), mat_size, mat_size);
    double end = omp_get_wtime();
    std::cout << "Execution Time: " << end - start << " seconds" << std::endl;
    delete []result;

    return 0;
}
