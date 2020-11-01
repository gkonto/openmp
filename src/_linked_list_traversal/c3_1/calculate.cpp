#include "calculate.hpp"

/*
 * COMMENT
 * The function fib() is called in the main program and also recursively called in the function fib() within an if condition.
 * The compiler creates a msked vector version and a non-msked vector version for the function fib() while retaining the
 * original scalar version of the fib() function.
 *
 *
 * Edo to simd kanei tipota ??
 */

#pragma omp declare simd inbranch
int fib(int n) {
	if (n <= 1) {
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}


void calculate(Llist<int> &l) {
	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();

#pragma omp simd
	for (int i = 0; i < nodes_num; ++i) {
		fib(node->data());
		node = node->next();
	}
}


