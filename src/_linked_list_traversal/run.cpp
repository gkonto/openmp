#include <iostream>
#include <iomanip>
#include <omp.h>
#include "l_list.hpp"
#include "auxiliaries.hpp"
#include "calculate.hpp"

namespace {
	struct Opts {
		size_t size = 0;
	};
}


int randI() {
	return rand() % 15 + 26;
}


void parseArgs(int argc, char **argv, Opts &o) {
	if (argc != 2) {
		std::cout << "Specify Linked List length!" << std::endl;
		exit(1);
	}
	read_value<size_t>(argv[1], o.size);
}


void fillList(Llist<int> &list, Opts &o) {
	Lnode<int> *head = list.head();
	Lnode<int> *temp = head;
	for (size_t i = 0; i < o.size - 1; ++i) {
		temp = temp->addNode(randI());	
	}
}


void printNode(Lnode<int> &node, void *args) {
	std::cout << node.data() << std::endl;
}


void showList(Llist<int> &list) {
	list.forEveryNode(printNode, nullptr);
}


int main(int argc, char **argv) {
	Opts o;
	parseArgs(argc, argv, o);
	srand(time(nullptr));

	Llist<int> l(randI());
	fillList(l, o);

	auto start = omp_get_wtime();
	calculate(l);

	auto end = omp_get_wtime();
	std::cout << "Execution Time : " << std::fixed 
		<< end - start << std::setprecision(5);
	std::cout << " sec " << std::endl;

	return 0;
}

