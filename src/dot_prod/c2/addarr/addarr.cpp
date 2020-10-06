#include <iostream>
#include <omp.h>
#include "addarr.hpp"

int dot_prod(int *B, int *C, size_t N)
{
	int sum0 = 0.0;
	int sum1 = 0.0;
	int sum2 = 0.0;
	int sum3 = 0.0;
#pragma omp target map(to: B[:N], C[:N]) map(tofrom: sum0, sum1)
#pragma omp teams num_teams(4)
	{
		 int i;
		 if (omp_get_num_teams() != 4)
			 abort();

		 if (omp_get_team_num() == 0) {
		 #pragma omp parallel for reduction(+:sum0)
			 for (i=0; i<N/4; i++)
				 sum0 += B[i] * C[i];
		 } else if (omp_get_team_num() == 1) {
		 #pragma omp parallel for reduction(+:sum1)
			 for (i=N/4; i<N/2; i++)
				 sum1 += B[i] * C[i];
		 } else if (omp_get_team_num() == 2) {
		 #pragma omp parallel for reduction(+:sum2)
			 for (i=N/2; i<3*N/4; i++)
				 sum2 += B[i] * C[i];
		 } else if (omp_get_team_num() == 3) {
		 #pragma omp parallel for reduction(+:sum2)
			 for (i=3*N/4; i<N; i++)
				 sum3 += B[i] * C[i];

		 }
	 }
	 return sum0 + sum1 + sum2 + sum3;
 }
