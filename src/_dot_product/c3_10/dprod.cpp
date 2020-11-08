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
 * Auto paizei kai vgazei sosta apotelesmata.
 * Osooso de mporo na xrisimopiohso reduction sto distribute.
 * An to xrisimopoihso vrisko lathos apotelesmata.
 * ki sto pdf examples 4.0.2 eno leei oti ginetai (sel235)
 * stin pragmatikotita de ginetai. des c3_9
 */
float dprod(size_t num, float *a, float *b) {
	float res = 0.0;
#pragma omp target teams map(res) map(tofrom: a[0:num], b[0:num])
#pragma omp distribute parallel for 
		for (size_t i = 0; i < num; ++i) {
#pragma omp critical
			res += a[i] * b[i];
		}
	return res;
}
