#include <iostream>
#include <iomanip>
#include "auxiliaries.hpp"
#include "matrix.hpp"
#include "factorization.hpp"
#include <omp.h>

namespace {
    struct Opts {
        std::string input_;
        bool verify_ = false;
    };
}


static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify rect matrix dimensions" << std::endl;
        exit(1);
    }

    read_value<std::string>(argv[1], o.input_);
    read_value<bool>(argv[2], o.verify_);
}


static void print(std::ostream& out, double **a, int rows, int cols) {
    size_t columns = cols;
    out << std::fixed << std::setprecision(5);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            if (column > 0)
                out << ' ';
            out << std::setw(9) << a[row][column];
        }
        out << std::endl;
    }
    std::cout << std::endl;
}


void verify(double **initial, double **lower, int dimension)
{
    double **upper = (double **)calloc(dimension, sizeof(double *));
    for (int i = 0; i < dimension; ++i) {
        upper[i] = (double *)calloc(dimension, sizeof(double));
    }
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            upper[i][j] = lower[j][i];
        }
    }
    print(std::cout, initial, dimension, dimension);
    print(std::cout, lower, dimension, dimension);
    print(std::cout, upper, dimension, dimension);

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            double tmp = 0;
            for (int k = 0; k < dimension; ++k) {
                tmp += lower[i][k] * upper[k][j];
            }
            if (std::abs(initial[i][j] - tmp) > 1e-6) {
                std::cout << initial[i][j] <<  " != " << tmp << std::endl;
                std::cout << "Failed verification!" << std::endl;
                exit(1);
            }
        }
    }
    std::cout << "Passed verification! " << std::endl;
}


int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    RectMatrixParser p(o.input_);
    RectMatrix *mat = p.build();

    double start = omp_get_wtime();
    double **result = cholesky(mat->entries(), mat->size());
    std::cout << result[0][0] << std::endl;
    double end = omp_get_wtime();

    if (o.verify_) {
        verify(mat->entries(), result, mat->size());
    }

    std::cout << "Execution Time: " << end - start << " seconds" << std::endl;
    delete []result;

    return 0;


}
