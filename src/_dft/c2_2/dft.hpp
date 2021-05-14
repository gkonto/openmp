#ifndef DFT_HPP
#define DFT_hpp

void dft(const double *ireal, const double *inimag, double *outreal, double *outimag,
        size_t n, int inverse);

#endif
