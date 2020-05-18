#include <stdio.h>
#include <iostream>
#include <omp.h>

double add1(double a, double b, double fact)
{
    double c;
    c = a + b + fact;
    return c;
}

double add2(double *a, double *b, int i, double fact)
{
    double c;
    c = a[i] + b[i] + fact;
    return c;
}

double add3(double *a, double *b, double fact)
{
    double c;
    c = *a + *b + fact;
    return c;
}

void work( double *a, double *b, int n )
{
    int i;
    double tmp;

    for ( i = 0; i < n; i++ ) {
        tmp = add1( a[i], b[i], 1.0);
        a[i] = add2( a, b, i, 1.0) + tmp;
        a[i] = add3(&a[i], &b[i], 1.0);
    }
}


int main(){
    int i;
    const int N=60000000;
    double *a = new double[N];
    double *b = new double[N];

    auto seconds = omp_get_wtime();
    for ( i=0; i<N; i++ ) {
        a[i] = i; b[i] = N-i;
    }

    work(a, b, N );
    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl; 

    /*
    for ( i=0; i<N; i++ ) {
        printf("%d %f\n", i, a[i]);
    }
    */

    delete []a;
    delete []b;

    return 0;
}
