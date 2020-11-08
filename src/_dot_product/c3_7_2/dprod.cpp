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
 * vgazei to idio sosta apotelesmata me to c3_7_1
 * Vevaia to verification vgazei lathos. Alla fainetai to got me to expected na einai to idio.
 * Ara isos kano lathos sto verification
 */
float dprod(size_t num, float *a, float *b) {
	float res = 0.0;
#pragma omp target  map(tofrom: res) map(to: a[0:num], b[0:num])
#pragma omp teams reduction(+ : res)
#pragma omp distribute parallel for reduction(+ : res)
		for (size_t i = 0; i < num; ++i) {
			res += a[i] * b[i];
		}
	return res;
}
