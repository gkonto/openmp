#include "dprod.hpp"
#include <stddef.h>

/*
I parallilopoihsi tis praksis tou esoterikou ginomenou epitigxanetai 
me tin eisagogi mias odigias openmp. Ostoso i odigia prepei na perilambanei
mia reduction frasi gia praksi prosthesis. sto telos tis parallilis perioxis, 
diladi tou telous tou vrogxou parallilopoihsis, oi diaforetikes idiotikes metablites 
sundiazontai metaksu tous, me ton combiner operator.
*/

#pragma omp declare simd notinbranch
double mult(double *a, double *b) {
	return *a * *b;
}

double dprod(size_t num, double *a, double *b) {
	double res = 0.0;
#pragma omp simd reduction(+ : res)
	for (size_t i = 0; i < num; ++i) {
		res += mult(&a[i], &b[i]);
	}
	return res;
}
