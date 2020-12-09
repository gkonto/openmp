#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <string.h>
#include <string>

// Source: Rosseta code
class RectMatrix {
    public:
        RectMatrix(int free = true) : free_(free) {}
        RectMatrix(int dimension, int free = true); 

        ~RectMatrix() {
            if (free_ && entries_) delete []entries_;
        }

        bool hasSize() const { return dimension_ != -1; }
        bool setSize(int dimension);
        int size() const { return dimension_; }
        double **entries() const { return entries_; }
        double *operator[] (size_t idx) { return entries_[idx]; }

    private:
        int dimension_ = -1;
        double **entries_ = nullptr;
        int free_ = false;
};


//Reads matrix from file
class RectMatrixParser {
    public:
        RectMatrixParser(const std::string &input_path);
        RectMatrix *build() { return matrix_; }
    private:
        RectMatrix  *matrix_;
};


#endif
