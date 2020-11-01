#include "calculate.hpp"
#include "../fibonacci.hpp"

void calculate(Llist<int> &l) {

	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();

#pragma omp parallel for
#pragma omp parallel sections
	for (int i = 0; i < nodes_num; ++i) {
#pragma omp section 
		{
			fib(node->data());
		}
		node = node->next();
	}
}


