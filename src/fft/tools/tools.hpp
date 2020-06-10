#ifndef TOOLS_HPP
#define TOOLS_HPP

using STEP_FUN = void (*)(int n, int mj, double a[], double b[], double c[], double d[], double w[], double sgn);

void ccopy(int n, double x[], double y[]);
double ggl(double *seed);
void cfft2(int n, double x[], double y[], double w[], double sgn, STEP_FUN fn);
#endif
