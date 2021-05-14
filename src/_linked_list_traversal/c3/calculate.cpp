#include "calculate.hpp"
#include <thread>

/* 
 * COMMENT
 * Question: Edo kanei kati to simd ?
 *
 */

#pragma omp declare simd 
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
        std::this_thread::sleep_for(std::chrono::milliseconds(node.data()));
		node = node->next();
	}
}


