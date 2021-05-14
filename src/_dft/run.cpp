/* 
 * (Alternate implementation using only real numbers.)
 * Computes the discrete Fourier transform (DFT) of the given complex vector.
 * All the array arguments must be non-NULL and have a length equal to n.
 */
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stddef.h>
#include <auxiliaries.hpp>
#include "dft.hpp"
#include <omp.h>

void compute_dft_real_pair(const double inreal[], const double inimag[],
		double outreal[], double outimag[], size_t n, int inverse) {
	
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


void pprint(double *arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) < 1e-6) {
            arr[i] = 0;
        }
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

namespace {
    struct Opts{
        int size = 0;
	bool verify = true;
    };
}


void parseArgs(int argc, char **argv, Opts &o) {
    if (argc < 2) {
        std::cout << "Specify three dimensions for matrix mult!" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.size);
}


void fill_arr(double *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 20 - 10;        
    }
}

static void verify(const double *real, const double *imag, const double *real_got, const double *imag_got, size_t size)
{
    for (int i = 0; i < size; ++i) {
        if (abs(real_got[i] - real[i]) > 1e-6) {
            std::cout << "Failed!!!" << std::endl;
            exit(1);
        }
    }
    std::cout << "Passed verification. Success!" << std::endl;
}

int main( int argc, char **argv ) {
    Opts o;
    parseArgs(argc, argv, o);

    double *real = new double[o.size];
    double *imag = new double[o.size];
    fill_arr(real, o.size);
    fill_arr(imag, o.size);
    double *real_out = new double[o.size];
    double *imag_out = new double[o.size];
    double *ireal_out = nullptr;
    double *iimag_out = nullptr;


    double start = omp_get_wtime();
    dft(real, imag, real_out, imag_out, o.size, 0);
    double end = omp_get_wtime();

    if (o.verify) {
        ireal_out = new double[o.size];
        iimag_out = new double[o.size];
        compute_dft_real_pair(real_out, imag_out, ireal_out, iimag_out, o.size, 1);
        verify(real, imag, ireal_out, iimag_out, o.size);
    }
    std::cout << "Execution Time: " << std::fixed << std::setprecision(3) << end - start << " sec" << std::endl;

    delete []real;
    delete []imag;
    delete []real_out;
    delete []imag_out;
    if (ireal_out) delete []ireal_out;
    if (iimag_out) delete []iimag_out;

    return 0;
}
