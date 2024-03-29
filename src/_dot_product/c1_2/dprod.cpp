#include "dprod.hpp"
#include <stddef.h>

/*
I parallilopoihsi tis praksis tou esoterikou ginomenou epitigxanetai 
me tin eisagogi mias odigias openmp. Ostoso i odigia prepei na perilambanei
mia reduction frasi gia praksi prosthesis. sto telos tis parallilis perioxis, 
diladi tou telous tou vrogxou parallilopoihsis, oi diaforetikes idiotikes metablites 
sundiazontai metaksu tous, me ton combiner operator.
*/

double dprod(size_t num, double *a, double *b) {
	double res = 0.0;
#pragma omp parallel shared(res)
	{
		double temp = 0.0;

#pragma omp for 
		for (size_t i = 0; i < num; ++i) {
			temp += a[i] * b[i];
		}
#pragma omp critical
		res += temp;

	}
	return res;
}
