#include <iostream>
#include <stddef.h>
#include <math.h>
#include "dft.hpp"
#include <omp.h>

/*
 * NOTES auto de kanei kan compile
 */


void dft(const double *inreal, const double *inimag,
		double *outreal, double *outimag, size_t n, int inverse) {
	
    double sumreal = 0;
    double sumimag = 0;
#pragma omp parallel for simd firstprivate(sumreal, sumimag)
	for (size_t k = 0; k < n; k++) {  // For each output element
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
            if (t == 0) {
                sumreal = 0;
                sumimag = 0;
            }
            if (inverse) angle = -angle;
			sumreal +=  inreal[t] * cos(angle) + inimag[t] * sin(angle);
			sumimag += -inreal[t] * sin(angle) + inimag[t] * cos(angle);
		}
        if (inverse) {
#pragma omp critical
            {
                outreal[k] = sumreal/n;
                outimag[k] = sumimag/n;
            }
        } else {
#pragma omp critical
            {
                outreal[k] = sumreal;
                outimag[k] = sumimag;
            } 
        }
    }
}
