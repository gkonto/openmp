#include "matrix.hpp"
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

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

RectMatrix::RectMatrix(int dim, int free) : dimension_(dim), free_(free) {
    entries_ = (double **)calloc(dim, sizeof(double *));
    for (int i = 0; i < dim; ++i) {
        entries_[i] = (double *)calloc(dim, sizeof(double *));
    }
}



RectMatrixParser::RectMatrixParser(const std::string &input_path) 
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


