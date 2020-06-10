#include <math.h>
#include "tools.hpp"

/*
  Purpose:
    CCOPY copies a complex vector.
  Discussion:
    The "complex" vector A[N] is actually stored as a double vector B[2*N].
    The "complex" vector entry A[I] is stored as:

      B[I*2+0], the real part,
      B[I*2+1], the imaginary part.
  Parameters:
    Input, int N, the length of the vector.
    Input, double X[2*N], the vector to be copied.
    Output, double Y[2*N], a copy of X.
*/
void ccopy(int n, double x[], double y[])
{
  for (int i = 0; i < n; i++) {
    y[i * 2 + 0] = x[i * 2 + 0];
    y[i * 2 + 1] = x[i * 2 + 1];
  }
}


/*
  Purpose:
    GGL generates uniformly distributed pseudorandom real numbers in [0,1].
  Parameters:
    Input/output, double *SEED, used as a seed for the sequence.
    Output, double GGL, the next pseudorandom value.
*/
double ggl(double *seed)
{
  double d2 = 0.2147483647e10;

  double t = *seed;
  t = fmod(16807.0 * t, d2);
  *seed = t;
  double value = (t - 1.0) / (d2 - 1.0);

  return value;
}



/*
  Purpose:
    CFFT2 performs a complex Fast Fourier Transform.
  Parameters:
    Input, int N, the size of the array to be transformed.
    Input/output, double X[2*N], the data to be transformed.
    On output, the contents of X have been overwritten by work information.
    Output, double Y[2*N], the forward or backward FFT of X.
    Input, double W[N], a table of sines and cosines.
    Input, double SGN, is +1 for a "forward" FFT and -1 for a "backward" FFT.
*/
void cfft2(int n, double x[], double y[], double w[], double sgn, STEP_FUN fn)
{
  int m = (int)(log((double)n) / log(1.99));
  int mj = 1;
  // Toggling switch for work array.
  int tgle = 1;
  fn(n, mj, &x[0 * 2 + 0], &x[(n / 2) * 2 + 0], &y[0 * 2 + 0], &y[mj * 2 + 0],
       w, sgn);

  if (n == 2)  return;

  for (int j = 0; j < m - 2; j++) {
    mj = mj * 2;
    if (tgle) {
      fn(n, mj, &y[0 * 2 + 0], &y[(n / 2) * 2 + 0], &x[0 * 2 + 0],
           &x[mj * 2 + 0], w, sgn);
      tgle = 0;
    } else {
      fn(n, mj, &x[0 * 2 + 0], &x[(n / 2) * 2 + 0], &y[0 * 2 + 0],
           &y[mj * 2 + 0], w, sgn);
      tgle = 1;
    }
  }
  // Last pass through data: move Y to X if needed.
  if (tgle) {
    ccopy(n, y, x);
  }

  mj = n / 2;
  fn(n, mj, &x[0 * 2 + 0], &x[(n / 2) * 2 + 0], &y[0 * 2 + 0], &y[mj * 2 + 0],
       w, sgn);
}


