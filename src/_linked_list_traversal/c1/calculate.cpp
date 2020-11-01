#include "calculate.hpp"
#include "../fibonacci.hpp"

void calculate(Llist<int> &l) {

	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();

#pragma omp parallel for
	for (int i = 0; i < nodes_num; ++i) {
		fib(node->data());
		node = node->next();
	}
}


