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
 * Does not compile
 */


float dprod(size_t num, float *a, float *b) {
	float res = 0.0;
#pragma omp target map(tofrom: res) map(to: a[0:num], b[0:num])
#pragma omp teams
#pragma omp distribute reduction(+ : res)
		for (size_t i = 0; i < num; ++i) {
			res += a[i] * b[i];
		}
	return res;
}
