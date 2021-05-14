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
 * einai i parallagi tis c3_7 pou omos vgazei sosta apotelesmata
 */
double dprod(size_t num, double *a, double *b) {
	double res = 0.0;
#pragma omp target  defaultmap(tofrom: scalar) map(to: a[0:num], b[0:num])
#pragma omp teams reduction(+ : res)
#pragma omp distribute parallel for reduction(+ : res)
		for (size_t i = 0; i < num; ++i) {
			res += a[i] * b[i];
		}
	return res;
}
