#include <stddef.h>
#include "dprod.hpp"


float dprod(size_t num, float *a, float *b) {
	float res = 0.0;
	for (size_t i = 0; i < num; ++i) {
		res += a[i] * b[i];
	}
	return res;
}
