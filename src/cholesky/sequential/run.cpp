#include <cassert>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include "omp.h"
#include "tools.hpp"
#include "auxiliaries.hpp"

// Source: Rosseta code
namespace {
    struct Opts {
        std::string input_;
    };
}


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


double **cholesky_factor(double **A, int rows, int cols) {
    assert(rows == cols);
    size_t n = rows;
    double **result = create_matrix(rows, cols);

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
    return result;
}

 
static void print_cholesky_factor(double **A, int rows, int cols) {
    std::cout << "Matrix:\n";
    print(std::cout, A, rows, cols);
    std::cout << "Cholesky factor:\n";
    print(std::cout, cholesky_factor(A, rows, cols), rows, cols);
}


static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify rect matrix dimensions" << std::endl;
        exit(1);
    }

    read_value<std::string>(argv[1], o.input_);
}


class RectMatrix {
    public:
        RectMatrix() = default;
        RectMatrix(int dimension) : dimension_(dimension) {}

        ~RectMatrix() {
            if (entries_) delete []entries_;
        }

        bool hasSize() const { return dimension_ != -1; }
        bool setSize(int dimension);
        int size() const { return dimension_; }
        double **entries() const { return entries_; }

        double *operator[] (size_t idx) { return entries_[idx]; }

    private:
        int dimension_ = -1;
        double **entries_ = nullptr;
};


bool RectMatrix::setSize(int dimension) {
    if (hasSize()) {
        return false;
    } 

    dimension_ = dimension;

    entries_ = new double *[dimension];
    for (int i = 0; i < dimension; ++i) {
        entries_[i] = new double[dimension];
    }
    return true;
}


//Reads matrix from file
class RectMatrixParser {
    public:
        RectMatrixParser(std::string input_path);
        RectMatrix *build() { return matrix_; }
    private:
        RectMatrix  *matrix_;
};


RectMatrixParser::RectMatrixParser(std::string input_path) 
    : matrix_(new RectMatrix) {

    std::ifstream infile(input_path);
    std::string buffer;
    int row = 0;
    while (std::getline(infile, buffer)) {
        std::stringstream l_buff(buffer);
        double value = 0;

        if (!matrix_->hasSize()) {
            int dimension = 0;
            while(l_buff >> value) {
                ++dimension;
            }
            matrix_->setSize(dimension);
        }

        std::stringstream l(buffer);
        int col = 0;
        while (l >> value) {
            (*matrix_)[row][col] = value; 
            ++col;
        }
        ++row;
    }
}

 
int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    RectMatrixParser p(o.input_);
    RectMatrix *mat = p.build();
    double start = omp_get_wtime();
    int mat_size = mat->size();
    double **result = cholesky_factor(mat->entries(), mat_size, mat_size);
    double end = omp_get_wtime();
    std::cout << "Execution Time: " << end - start << " seconds" << std::endl;
    delete []result;

    return 0;
}
