#ifndef SAXPY_HPP
#define SAXPY_HPP
#include <cstddef>

struct float64
{
    union {
        float v_;
        char padding_[64];
    };
};

void saxpy(size_t n, float a, const float64 *x, float64 *y);

#endif