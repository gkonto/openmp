# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <omp.h>
#include "auxiliaries.hpp"

using namespace std;

namespace {
    struct Opts {
        int num_threads;
        int dim;
    };
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify dimension and number of threads" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.dim);
    read_value<int>(argv[2], o.num_threads);
}

int main (int argc, char **argv)
{
    Opts o;
    parseArgs(argc, argv, o);
//  omp_set_num_threads(1);
  double *b = nullptr;
  double d = 0.0;
  int i = 0;
  int it = 0;
  int m = 0;
  int n = 0;
  double r = 0.0;
  double t = 0.0;
  double *x = nullptr;
  double *xnew = nullptr;

  omp_set_num_threads(o.num_threads);
  m = o.dim;
  n = o.dim;
    double start = omp_get_wtime();

  b = new double[n];
  x = new double[n];
  xnew = new double[n];

  timestamp();
  std::cout << "\n";
  std::cout << "JACOBI_OPENMP:\n";
  std::cout << "  C/OpenMP version\n";
  std::cout << "  Jacobi iteration to solve A*x=b.\n";
  std::cout << "\n";
  std::cout << "  Number of variables  N = " << n << "\n";
  std::cout << "  Number of iterations M = " <<  m << "\n";

  std::cout << "\n";
  std::cout << "  IT     l2(dX)    l2(resid)\n";
  std::cout << "\n";

# pragma omp parallel private ( i )
  {
//  Set up the right hand side.
# pragma omp for
    for (i = 0; i < n; i++) {
      b[i] = 0.0;
    }

    b[n-1] = (double)(n + 1);
//  Initialize the solution estimate to 0.
//  Exact solution is (1,2,3,...,N).
# pragma omp for
    for (i = 0; i < n; i++) {
      x[i] = 0.0;
    }

  }
//  Iterate M times.
  for (it = 0; it < m; it++) {
# pragma omp parallel private ( i, t )
    {
//  Jacobi update.
# pragma omp for
      for (i = 0; i < n; i++) {
        xnew[i] = b[i];
        if (0 < i) {
          xnew[i] = xnew[i] + x[i-1];
        }
        if ( i < n - 1 ) {
          xnew[i] = xnew[i] + x[i+1];
        }
        xnew[i] = xnew[i] / 2.0;
      }
//  Difference.
      d = 0.0;
# pragma omp for reduction (+:d)
      for (i = 0; i < n; i++) {
        d = d + pow ( x[i] - xnew[i], 2 );
      }
//  Overwrite old solution.
# pragma omp for
      for (i = 0; i < n; i++) {
        x[i] = xnew[i];
      }
//  Residual.
      r = 0.0;
# pragma omp for reduction ( + : r )
      for (i = 0; i < n; i++) {
        t = b[i] - 2.0 * x[i];
        if ( 0 < i )
        {
          t = t + x[i-1];
        }
        if ( i < n - 1 )
        {
          t = t + x[i+1];
        }
        r = r + t * t;
      }

# pragma omp master
      {
        if ( it < 10 || m - 10 < it )
        {
            std::cout << "  " << setw(8) << it
               << "  " << setw(14) << sqrt ( d )
               << "  " << sqrt ( r ) << "\n";
        }
        if ( it == 9 ) {
            std::cout << "  Omitting intermediate results.\n";
        }
      }

    }

  }
//
//  Write part of final estimate.
//
  std::cout << "\n";
  std::cout << "  Part of final solution estimate:\n";
  std::cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
      std::cout << "  " << setw(8) << i
         << "  " << setw(14) << x[i] << "\n";
  }
  std::cout << "...\n";
  for ( i = n - 11; i < n; i++ )
  {
      std::cout << "  " << setw(8) << i
         << "  " << setw(14) << x[i] << "\n";
  }

//  Free memory.
  delete [] b;
  delete [] x;
  delete [] xnew;

//  Terminate.
  std::cout << "\n";
  std::cout << "JACOBI_OPENMP:\n";
  std::cout << "  Normal end of execution.\n";
  std::cout << "\n";
  timestamp ( );
  std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds" << std::endl;

  return 0;
}


