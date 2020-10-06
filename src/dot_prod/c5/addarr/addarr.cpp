#include <iostream>
#include <omp.h>
#include "addarr.hpp"

int dot_prod(int B[], int C[], size_t size)
{
	float sum = 0.0;
	int i;
#pragma omp target map(to: B[0:size], C[0:size]) map(tofrom: sum)
#pragma omp teams num_teams(8) thread_limit(16) reduction(+:sum)
#pragma omp distribute parallel for reduction(+:sum) \
	dist_schedule(static, 1024) schedule(static, 64)
	for (i=0; i<size; i++)
		sum += B[i] * C[i];
	return sum;
}
