#include "calculate.hpp"
#include <thread>
#include <vector>
using namespace std;

int calculate(Llist<int> &l) {
    Lnode<int> *node = l.head();
	size_t nodes_num = l.size();
    std::vector<int> nodes(nodes_num);

    for (size_t i = 0; i < nodes_num; ++i) {
        nodes[i] = node->data();
		node = node->next();
    }

    int num_nodes = 0;
#pragma omp parallel for schedule(dynamic) shared(num_nodes)
	for (size_t i = 0; i < nodes_num; ++i) {
        this_thread::sleep_for(chrono::nanoseconds(randI()));
#pragma omp atomic
        num_nodes += nodes[i];
	}
    return num_nodes;
}



