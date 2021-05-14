#include <iostream>
#include <iomanip>
#include <omp.h>
#include "l_list.hpp"
#include "auxiliaries.hpp"
#include "calculate.hpp"
#include <bits/stdc++.h>


namespace {
	struct Opts {
		size_t size = 0;
	};
}


int randI() {
	return rand() % 5 + 1;
}

void parseArgs(int argc, char **argv, Opts &o) {
	if (argc != 2) {
		std::cout << "Specify Linked List length!" << std::endl;
		exit(1);
	}
	read_value<size_t>(argv[1], o.size);
}


int fillList(Llist<int> &list, Opts &o) {
	Lnode<int> *head = list.head();
	Lnode<int> *temp = head;
    int verify_val = 0;
	for (size_t i = 0; i < o.size - 1; ++i) {
		temp = temp->addNode(i);	
        verify_val += i;
	}
    return verify_val;
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

	Llist<int> l(0);
	int verify_val = fillList(l, o);

	auto start = omp_get_wtime();
	int ret = calculate(l);
	auto end = omp_get_wtime();

    if (verify_val != ret) {
        std::cout << "Error: Expected : " << verify_val << " Got: " << ret << std::endl;
        exit(1);
    }

	std::cout << "Execution Time : " << std::fixed 
		<< std::setprecision(3) << end - start;
	std::cout << " sec " << std::endl;


	return 0;
}

