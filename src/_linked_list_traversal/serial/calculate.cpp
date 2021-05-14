#include "calculate.hpp"
#include <thread>


void dowork(Lnode<int> &node, void *args) {
    int *num_nodes = static_cast<int *>(args);
    std::this_thread::sleep_for(std::chrono::nanoseconds(rand() % 5 + 1));
    *num_nodes += node.data();
}

int calculate(Llist<int> &l) {

    int number_of_nodes = 0;
	l.forEveryNode(dowork, &number_of_nodes);

    return number_of_nodes;
}
