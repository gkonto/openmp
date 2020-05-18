#include <iostream>
#include <fstream> // For files manipulation
#include <complex> // for complex numbers
#include <omp.h>

using namespace std;

double width  = 3000;
double height = 3000;

static int value(int x, int y) {
    complex<double> point((double)x/width - 1.5, (double)y/height-0.5);
    // we divide by the image dimensions to get values smaller than 1
    // then apply a translation
    
    complex<double> z(0, 0);
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

int main() {
    ofstream my_image("mandelbrot.ppm");

    double start = omp_get_wtime();
    if (my_image.is_open()) {
        my_image << "P3\n" << width << " " << height << " 255\n";
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int val  = value(i, j);
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


