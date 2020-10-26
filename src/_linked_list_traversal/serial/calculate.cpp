#include "calculate.hpp"
#include "../fibonacci.hpp"


void calcFib(Lnode<int> &node, void *args) {
	fib(node.data());
}

void calculate(Llist<int> &l) {
	l.forEveryNode(calcFib, nullptr);
}
