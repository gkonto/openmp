#include <iostream>
#include <fstream> // For files manipulation
#include <complex> // for complex numbers
#include <omp.h>
#include "auxiliaries.hpp"

double width  = 100;
double height = 100;

namespace {
    struct Opts {
        int width = 0;
        int height = 0;
    };
}

static int value(const std::complex<double> &point) {
    // we divide by the image dimensions to get values smaller than 1
    // then apply a translation
    
    std::complex<double> z(0, 0);
    unsigned int nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 34) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 34) {
        return (255 * nb_iter) / 33;
    } else { 
        return 0;
    }
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify height and width (pixels)" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.width);
    read_value<int>(argv[2], o.height);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    std::ofstream my_image("mandelbrot.ppm");

    double start = omp_get_wtime();
    if (my_image.is_open()) {
        my_image << "P3\n" << o.width << " " << o.height << " 255\n";
        for (int i = 0; i < o.width; ++i) {
            for (int j = 0; j < o.height; ++j) {

                std::complex<double> point((double)i/width - 1.5, (double)j/height-0.5);
                int val  = value(point);
                my_image << val << ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        my_image.close();
    } else {
        std::cout << "Could not open the file" << std::endl;
        return 0;
    }
    double end = omp_get_wtime();
    std::cout << "Time Elapsed: " << end - start << std::endl;
    
    return 0;
}


