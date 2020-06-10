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
