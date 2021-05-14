#include <stddef.h>
#include "dprod.hpp"


double dprod(size_t num, double *a, double *b) {
	double res = 0.0;
	for (size_t i = 0; i < num; ++i) {
		res += a[i] * b[i];
	}
	return res;
}
