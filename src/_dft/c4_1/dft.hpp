#ifndef DFT_HPP
#define DFT_hpp

#include <omp.h>

void dft(const double *ireal, const double *inimag, double *outreal, double *outimag,
        size_t n, int inverse);

#pragma omp declare target
extern double cal_real(double real, double imag, double angle);
#pragma omp end declare target

#endif
