#include <iostream>
#include <stddef.h>
#include <math.h>
#include "dft.hpp"

/*
 * NOTES.
 * De mporo na to kano na treksei giati kaleitai i sin kai cos,
 * tis opoios de mporo na tis peraso sto target.
 */

double cal_real(double real, double imag, double angle)
{
    return real * cos(angle) + imag * sin(angle);
}



void dft(const double *inreal, const double *inimag,
		double *outreal, double *outimag, size_t n, int inverse) {
#pragma omp target map(inreal[0:n], inimag[0:n], outreal[0:n], outimag[0:n], n, inverse)
#pragma omp parallel for 
	for (size_t k = 0; k < n; k++) {  // For each output element
		double sumreal = 0;
		double sumimag = 0;
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
            if (inverse) angle = -angle;
			sumreal += cal_real(inreal[t], inimag[t], angle);
			//sumimag += -inreal[t] * sin(angle) + inimag[t] * cos(angle);
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
