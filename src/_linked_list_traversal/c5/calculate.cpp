#include "calculate.hpp"


/* COMMENT
 * de mporo na kano compile etsi opos einai kai de katalabaino giati 
 */

#pragma omp declare target 
extern int fib(int n);
#pragma omp end declare target

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	return fib(n-1) + fib(n-2);
}


void fib_wrapper(int n) {
}


void calculate(Llist<int> &l) {
	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();
	int i = 0;
	
#pragma omp target
	{
		fib(5);
	}
	/*
//#pragma omp target map(to: node, nodes_num)
#pragma omp target map(to: node)
#pragma omp parallel for private(i)
	for (i = 0; i < 1; ++i) {
		fib_wrapper(5);
		//fib(node->data());
		//node = node->next();
	}
	*/
}


