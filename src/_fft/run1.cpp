# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <omp.h>

using namespace std;

void ccopy(int n, double x[], double y[]);
void cfft2(int n, double x[], double y[], double w[], double sgn);
void cffti(int n, double w[]);
double cpu_time();
double ggl(double *ds);
void step(int n, int mj, double a[], double b[], double c[], double d[], 
         double w[], double sgn);
void timestamp();

//****************************************************************************80


//****************************************************************************80
//  Purpose:
//    MAIN is the main program for FFT_SERIAL.
//  Discussion:
//    The complex data in an N vector is stored as pairs of values in a
//    real vector of length 2*N.
int main()
{
  int nits = 10000;

  timestamp();
  cout << "\n";
  cout << "FFT_SERIAL\n";
  cout << "  C++ version\n";
  cout << "\n";
  cout << "  Demonstrate an implementation of the Fast Fourier Transform\n";
  cout << "  of a complex data vector.\n";
//
//  Prepare for tests.
//
  cout << "\n";
  cout << "  Accuracy check:\n";
  cout << "\n";
  cout << "    FFT ( FFT ( X(1:N) ) ) == N * X(1:N)\n";
  cout << "\n";
  cout << "             N      NITS    Error         Time          Time/Call     MFLOPS\n";
  cout << "\n";

  static double seed  = 331.0;
  int n = 1;
//
//  LN2 is the log base 2 of N.  Each increase of LN2 doubles N.
//
  for (int ln2 = 1; ln2 <= 1; ln2++)
  {
    n = 8 * n;
//
//  Allocate storage for the complex arrays W, X, Y, Z.  
//
//  We handle the complex arithmetic,
//  and store a complex number as a pair of doubles, a complex vector as a doubly
//  dimensioned array whose second dimension is 2. 
//
    double *w = new double[  n]; // 8
    double *x = new double[2*n]; // 8
    double *y = new double[2*n]; // 8
    double *z = new double[2*n]; // 8

    for (int icase = 0; icase < 2; icase++) {
        for (int i = 0; i < 2 * n; i = i + 2) {
          double z0 = ggl(&seed);
          double z1 = ggl(&seed);
          x[i] = z0;
          z[i] = z0;
          x[i+1] = z1;
          z[i+1] = z1;
        }
      //  Initialize the sine and cosine tables.
      cffti(n, w);
//  Transform forward, back 
        double sgn = + 1.0;
        cfft2(n, x, y, w, sgn);
        sgn = - 1.0;
        cfft2(n, y, x, w, sgn);
        
//  Results should be same as initial multiplied by N.
        double fnm1 = 1.0 / ( double ) n;
        double error = 0.0;
        for (int i = 0; i < 2 * n; i = i + 2) {
          error = error 
          + pow ( z[i]   - fnm1 * x[i], 2 )
          + pow ( z[i+1] - fnm1 * x[i+1], 2 );
        }
        error = sqrt ( fnm1 * error );
        cout << setw(12) << n
             << "  " << setw(8) << nits
             << "  " << setw(12) << error;
    }

    if ((ln2 % 4) == 0) {
      nits = nits / 10;
    }

    if (nits < 1) {
      nits = 1;
    }
    delete [] w;
    delete [] x;
    delete [] y;
    delete [] z;
  }

  cout << "\n";
  cout << "FFT_SERIAL:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp();

  return 0;
}
//****************************************************************************80


//****************************************************************************80
//  Purpose:
//    CCOPY copies a complex vector.
//  Discussion:
//    The "complex" vector A[N] is actually stored as a double vector B[2*N].
//    The "complex" vector entry A[I] is stored as:
//      B[I*2+0], the real part,
//      B[I*2+1], the imaginary part.
//  Parameters:
//    Input, int N, the length of the "complex" array.
//    Input, double X[2*N], the array to be copied.
//    Output, double Y[2*N], a copy of X.
void ccopy(int n, double x[], double y[]) {
  for (int i = 0; i < n; i++) {
    y[i*2+0] = x[i*2+0];
    y[i*2+1] = x[i*2+1];
  }
}
//****************************************************************************80


//****************************************************************************80
//
//  Purpose:
//
//    CFFT2 performs a complex Fast Fourier Transform.
//
//  Parameters:
//    Input, int N, the size of the array to be transformed.
//    Input/output, double X[2*N], the data to be transformed.  
//    On output, the contents of X have been overwritten by work information.
//    Output, double Y[2*N], the forward or backward FFT of X.
//    Input, double W[N], a table of sines and cosines.
//    Input, double SGN, is +1 for a "forward" FFT and -1 for a "backward" FFT.
void cfft2(int n, double x[], double y[], double w[], double sgn) {
   int m = (int)(log((double)n) / log(1.99));
   int mj   = 1;

//  Toggling switch for work array.
  int tgle = 1;
  step(n, mj, &x[0*2+0], &x[(n/2)*2+0], &y[0*2+0], &y[mj*2+0], w, sgn);

  if ( n == 2 ) {
    return;
  }

  for (int j = 0; j < m-2; j++) {
    mj = mj * 2;
    if (tgle) {
      step(n, mj, &y[0*2+0], &y[(n/2)*2+0], &x[0*2+0], &x[mj*2+0], w, sgn);
      tgle = 0;
    } else {
      step(n, mj, &x[0*2+0], &x[(n/2)*2+0], &y[0*2+0], &y[mj*2+0], w, sgn);
      tgle = 1;
    }
  }

//  Last pass thru data: move y to x if needed 
  if (tgle) {
    ccopy(n, y, x);
  }

  mj = n / 2;
  step(n, mj, &x[0*2+0], &x[(n/2)*2+0], &y[0*2+0], &y[mj*2+0], w, sgn);

}
//****************************************************************************80


//****************************************************************************80
//  Purpose:
//    CFFTI sets up sine and cosine tables needed for the FFT calculation.
//  Parameters:
//    Input, int N, the size of the array to be transformed.
//    Output, double W[N], a table of sines and cosines.
void cffti(int n, double w[]) {
  const double pi = 3.141592653589793;
  int n2 = n / 2;
  double aw = 2.0 * pi / ((double )n);

  for (int i = 0; i < n2; i++) {
    double arg = aw * ((double) i);
    w[i*2+0] = cos(arg);
    w[i*2+1] = sin(arg);
  }
}
//****************************************************************************80


//****************************************************************************80
//  Purpose:
//    CPU_TIME reports the elapsed CPU time.
//  Parameters:
//    Output, double CPU_TIME, the current total elapsed CPU time in second.
double cpu_time() {
  double value = (double) clock() / (double) CLOCKS_PER_SEC;

  return value;
}
//****************************************************************************80


//****************************************************************************80
//  Purpose:
//    GGL generates uniformly distributed pseudorandom numbers. 
//  Parameters:
//    Input/output, double *SEED, used as a seed for the sequence.
//    Output, double GGL, the next pseudorandom value.
double ggl(double *seed)
{
  double d2 = 0.2147483647e10;

  double t = *seed;
  t = fmod ( 16807.0 * t, d2 );
  *seed = t;
  double value = ( t - 1.0 ) / ( d2 - 1.0 );

  return value;
}
//****************************************************************************80


//****************************************************************************80
//    STEP carries out one step of the workspace version of CFFT2.
void step ( int n, int mj, double a[], double b[], double c[],
  double d[], double w[], double sgn )
{
  double wjw[2];

  int mj2 = 2 * mj;
  int lj = n / mj2;

  for (int j = 0; j < lj; j++) {
    int jw = j * mj;
    int ja  = jw;
    int jb  = ja;
    int jc  = j * mj2;
    int jd  = jc;

    wjw[0] = w[jw*2+0]; 
    wjw[1] = w[jw*2+1];

    if ( sgn < 0.0 ) {
      wjw[1] = - wjw[1];
    }

    for (int k = 0; k < mj; k++) {
      c[(jc+k)*2+0] = a[(ja+k)*2+0] + b[(jb+k)*2+0];
      c[(jc+k)*2+1] = a[(ja+k)*2+1] + b[(jb+k)*2+1];

      double ambr = a[(ja+k)*2+0] - b[(jb+k)*2+0];
      double ambu = a[(ja+k)*2+1] - b[(jb+k)*2+1];

      d[(jd+k)*2+0] = wjw[0] * ambr - wjw[1] * ambu;
      d[(jd+k)*2+1] = wjw[1] * ambr + wjw[0] * ambu;
    }
  }
}
//****************************************************************************80


//****************************************************************************80
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
void timestamp()
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
