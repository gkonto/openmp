#include "calculate.hpp"
#include <thread>
#include <vector>

int calculate(Llist<int> &l) {
	Lnode<int> *node = l.head();
	size_t nodes_num = l.size();

    std::vector<int> nodes(nodes_num);

    for (size_t i = 0; i < nodes_num; ++i) {
        nodes[i] = node->data();
		node = node->next();
    }

    int num_nodes = 0;
#pragma omp parallel for simd shared(num_nodes)
	for (size_t i = 0; i < nodes_num; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(randI()));
#pragma omp critical
        num_nodes += nodes[i];
	}
    return num_nodes;
}


