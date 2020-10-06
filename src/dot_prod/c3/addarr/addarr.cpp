#include <iostream>
#include <omp.h>
#include "addarr.hpp"

#define min(x, y) (((x) < (y)) ? (x) : (y))

int dot_prod(int B[], int C[], size_t N)
{
	int sum = 0.0;
	int i, i0;
	int block_size = 10000;
#pragma omp target map(to: B[0:N], C[0:N]) map(tofrom: sum)
#pragma omp teams reduction(+:sum)
#pragma omp distribute
	for (i0=0; i0<N; i0 += block_size)
#pragma omp parallel for reduction(+:sum)
		for (i=i0; i< min(i0+block_size,N); i++)
			sum += B[i] * C[i];
	return sum;
}

#undef min
