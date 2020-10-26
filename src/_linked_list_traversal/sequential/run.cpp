#include <iostream>
#include <omp.h>
#include "tools/l_list.hpp"
#include "fib.hpp"
#include "auxiliaries.hpp"

#define FIBVAL 33

struct Opts {
    int num_nodes_ = 0;
};

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify number of linked list nodes" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.num_nodes_);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    Node *head = init_nodes(o.num_nodes_, FIBVAL);
    Node *p = head;

    double start = omp_get_wtime();
    while(p != nullptr) {
        fib(p->data_);
        p = p->next_;
    }
    double end = omp_get_wtime();

    delete head;

    std::cout << "Time Elapsed: " << end - start << std::endl;
    return 0;
}
