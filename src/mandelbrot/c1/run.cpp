#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <omp.h>
#include "auxiliaries.hpp"

using namespace std;

namespace {
    struct Opts {
        int width = 0;
        int height = 0;
        int num_threads = 0;
    };
}

class MatrixInt2D {
    public:
      MatrixInt2D(int m, int n);
      ~MatrixInt2D();
        
      int* operator[](size_t idx) {
          return a_[idx];
      }
    private:
        int **a_ = nullptr;
        int m_ = 0;
        int n_ = 0;
};

MatrixInt2D::MatrixInt2D(int m, int n) : m_(m), n_(n) {
    a_ = new int *[m_];
    if (!a_) {
        std::cerr << "\n";
        std::cerr << "I4PP_NEW - Fatal error!\n";
        std::cerr << "  Unable to allocate row pointer array.\n";
        exit(1);
    }

    for (int i = 0; i < m_; i++) {
        a_[i] = new int[n_];
        if (a_[i] == NULL) {
            cerr << "\n";
            cerr << "I4PP_NEW - Fatal error!\n";
            cerr << "  Unable to allocate row array.\n";
            exit(1);
        }
    }
}


MatrixInt2D::~MatrixInt2D() {
      for (int i = 0; i < m_; ++i) {
          delete[] a_[i];
      }

      delete[] a_;
}


static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 4) {
        std::cout << "Specify height, width(pixels) and num of threads" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.width);
    read_value<int>(argv[2], o.height);
    read_value<int>(argv[3], o.num_threads);
}


static void greetings(double x_min, double x_max, double y_min, double y_max, int count_max, int m, int n ) {
    timestamp();
    std::cout << "\n";
    std::cout << "MANDELBROT_OPENMP\n";
    std::cout << "  C++/OpenMP version\n";
    std::cout << "\n";
    std::cout << "  Create an ASCII PPM image of the Mandelbrot set.\n";
    std::cout << "\n";
    std::cout << "  For each point C = X + i*Y\n";
    std::cout << "  with X range [" << x_min << "," << x_max << "]\n";
    std::cout << "  and  Y range [" << y_min << "," << y_max << "]\n";
    std::cout << "  carry out " << count_max << " iterations of the map\n";
    std::cout << "  Z(n+1) = Z(n)^2 + C.\n";
    std::cout << "  If the iterates stay bounded (norm less than 2)\n";
    std::cout << "  then C is taken to be a member of the set.\n";
    std::cout << "\n";
    std::cout << "  An ASCII PPM image of the set is created using\n";
    std::cout << "    M = " << m << " pixels in the X direction and\n";
    std::cout << "    N = " << n << " pixels in the Y direction.\n";
}


static void bye(const std::string &filename) {
    std::cout << "\n";
    std::cout << "  Graphics data written to \"" << filename << "\".\n";

    // Terminate.
    std::cout << "\n";
    std::cout << "MANDELBROT_OPENMP\n";
    std::cout << "  Normal end of execution.\n";
    std::cout << "\n";
    timestamp();


}

//****************************************************************************80
//  Purpose
//    MAIN is the main program for MANDELBROT_OPENMP.
//  Discussion:
//    MANDELBROT_OPENMP computes an image of the Mandelbrot set.
int main(int argc, char **argv)
{
  Opts o;
  parseArgs(argc, argv, o);
  int m = o.width;
  int n = o.height;

  int count_max = 2000;
  string filename = "mandelbrot.ppm";
  ofstream output;
  double x_max = 1.25;
  double x_min = -2.25;
  double y_max = 1.75;
  double y_min = -1.75;

  MatrixInt2D b = MatrixInt2D(m, n);
  MatrixInt2D count = MatrixInt2D(m, n);
  MatrixInt2D g = MatrixInt2D(m, n);
  MatrixInt2D r = MatrixInt2D(m, n);

  greetings(x_min, x_max, y_min, y_max, count_max, m, n);
  omp_set_num_threads(o.num_threads);
  double wtime = omp_get_wtime();
  // Carry out the iteration for each pixel, determining COUNT.
#pragma omp parallel shared(b, count, count_max, g, r, x_max, x_min, y_max,    \
                            y_min) 
  {
#pragma omp for

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        double x = ((double)(j - 1) * x_max + (double)(m - j) * x_min) /
            (double)(m - 1);

        double y = ((double)(i - 1) * y_max + (double)(n - i) * y_min) /
            (double)(n - 1);

        count[i][j] = 0;

        double x1 = x;
        double y1 = y;

        for (int k = 1; k <= count_max; k++) {
          double x2 = x1 * x1 - y1 * y1 + x;
          double y2 = 2 * x1 * y1 + y;

          if (x2 < -2.0 || 2.0 < x2 || y2 < -2.0 || 2.0 < y2) {
            count[i][j] = k;
            break;
          }
          x1 = x2;
          y1 = y2;
        }

        if ((count[i][j] % 2) == 1) {
          r[i][j] = 255;
          g[i][j] = 255;
          b[i][j] = 255;
        } else {
          int c = (int)(255.0 * sqrt(sqrt(sqrt(((double)(count[i][j]) /
                                            (double)(count_max))))));
          r[i][j] = 3 * c / 5;
          g[i][j] = 3 * c / 5;
          b[i][j] = c;
        }
      }
    }
  }

  wtime = omp_get_wtime() - wtime;
  std::cout << "\n";
  std::cout << "  Time = " << wtime << " seconds.\n";

  //Write data to an ASCII PPM file.
  output.open(filename.c_str());

  output << "P3\n";
  output << n << "  " << m << "\n";
  output << 255 << "\n";
  for (int i = 0; i < m; i++) {
    for (int jlo = 0; jlo < n; jlo = jlo + 4) {
      int jhi = std::min(jlo + 4, n);
      for (int j = jlo; j < jhi; j++) {
        output << "  " << r[i][j] << "  " << g[i][j] << "  " << b[i][j] << "\n";
      }
      output << "\n";
    }
  }

  output.close();
  bye(filename);

  return 0;
}

