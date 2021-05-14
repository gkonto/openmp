#include <iostream>
#include "calculate.hpp"
#include <thread>

int calculate(Llist<int> &l) {
	Lnode<int> *node = l.head();

    int num_nodes = 0;
#pragma omp parallel shared(num_nodes)
	{
#pragma omp single
		{
			while (node) {
#pragma omp task shared(node)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(randI()));
#pragma omp atomic
                    num_nodes += node->data();
                }
				node = node->next();
			}
		}
	}
    return num_nodes;
}


