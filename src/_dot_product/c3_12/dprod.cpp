#include "dprod.hpp"
#include <stddef.h>

/*
I parallilopoihsi tis praksis tou esoterikou ginomenou epitigxanetai 
me tin eisagogi mias odigias openmp. Ostoso i odigia prepei na perilambanei
mia reduction frasi gia praksi prosthesis. sto telos tis parallilis perioxis, 
diladi tou telous tou vrogxou parallilopoihsis, oi diaforetikes idiotikes metablites 
sundiazontai metaksu tous, me ton combiner operator.
*/


/* COMMENT
 * Critical does not compile with simd. It needs simd ordered
 */
float dprod(size_t num, float *a, float *b) {
	float res = 0.0;
#pragma omp target teams map(res) map(tofrom: a[0:num], b[0:num])
#pragma omp distribute simd reduction(+ : res)
		for (size_t i = 0; i < num; ++i) {
#pragma omp critical
			res += a[i] * b[i];
		}
	return res;
}
