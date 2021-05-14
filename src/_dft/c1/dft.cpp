#include <iostream>
#include <stddef.h>
#include <math.h>
#include "dft.hpp"
#include <omp.h>


void dft(const double *inreal, const double *inimag,
		double *outreal, double *outimag, size_t n, int inverse) {
	
#pragma omp parallel for
	for (size_t k = 0; k < n; k++) {  // For each output element
		double sumreal = 0;
		double sumimag = 0;
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
            if (inverse) angle = -angle;
			sumreal +=  inreal[t] * cos(angle) + inimag[t] * sin(angle);
			sumimag += -inreal[t] * sin(angle) + inimag[t] * cos(angle);
		}
        if (inverse) {
            outreal[k] = sumreal/n;
            outimag[k] = sumimag/n;
        } else {
            outreal[k] = sumreal;
            outimag[k] = sumimag;
        } 
    }
}
