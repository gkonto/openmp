#include <iostream>
#include <omp.h>
#include "addarr.hpp"


int dot_prod(int B[], int C[], size_t N)
{
	float sum = 0;
	int i;
#pragma omp target teams map(to: B[0:N], C[0:N]) \
	defaultmap(tofrom:scalar) reduction(+:sum)
#pragma omp distribute parallel for reduction(+:sum)
	for (i=0; i<N; i++)
		sum += B[i] * C[i];

	return sum;
}
