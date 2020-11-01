#include <iostream>
#include "calculate.hpp"
#include "../fibonacci.hpp"

void calculate(Llist<int> &l) {

	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();

#pragma omp parallel
	{
#pragma omp single
		{
			while (node) {
#pragma omp task shared(node)
				fib(node->data());
				node = node->next();
			}

		}
	}
}


