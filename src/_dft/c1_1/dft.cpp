#include <iostream>
#include <stddef.h>
#include <math.h>
#include "dft.hpp"
#include <omp.h>

/*
 * Thelo na kano collapse (se sxesi me to c1)
 */

void dft(const double *inreal, const double *inimag,
		double *outreal, double *outimag, size_t n, int inverse) {
	
        double sumreal = 0.0;
        double sumimag = 0.0;
#pragma omp parallel for collapse(2)
	for (size_t k = 0; k < n; k++) {  // For each output element
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
            if (inverse) {
                angle = -angle;
#pragma omp critical
                {
                    outreal[k] += ( inreal[t] * cos(angle) + inimag[t] * sin(angle))/n;
                    outimag[k] += (-inreal[t] * sin(angle) + inimag[t] * cos(angle))/n;
                }    
            } else {
#pragma omp critical 
                {
                    outreal[k] +=  inreal[t] * cos(angle) + inimag[t] * sin(angle);
                    outimag[k] += -inreal[t] * sin(angle) + inimag[t] * cos(angle);
                }
            }
		}
    }
}
