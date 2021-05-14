#include <iostream>
#include "calculate.hpp"
#include <thread>

int calculate(Llist<int> &l) {
	Lnode<int> *node = l.head();

    int num_nodes = 0;
#pragma omp parallel shared(num_nodes)
	{
#pragma omp single nowait
		{
			while (node) {
#pragma omp task shared(node) mergeable
                {
                    std::this_thread::sleep_for(std::chrono::nanoseconds(randI()));
#pragma omp atomic
                    num_nodes += node->data();
                }
				node = node->next();
			}
		}
	}
    return num_nodes;
}


