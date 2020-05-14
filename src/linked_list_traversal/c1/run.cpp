#include <iostream>
#include <omp.h>
#include <vector>
#include "tools/l_list.hpp"
#include "fib.hpp"
#include "auxiliaries.hpp"

#define FIBVAL 33

struct Opts {
    int num_nodes_ = 0;
    int num_threads_ = 0;
};

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify number of linked list nodes and num of threads" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.num_nodes_);
    read_value<int>(argv[2], o.num_threads_);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    Node *head = init_nodes(o.num_nodes_, FIBVAL);
    omp_set_num_threads(o.num_threads_);

    Node *p = head;
    double start = omp_get_wtime();
    std::vector<Node *> nodes_(o.num_nodes_);
    for (int i = 0; i < o.num_nodes_; ++i) {
        nodes_[i] = p;
        p = p->next_;
    }

#pragma omp parallel
    {
#pragma omp for schedule(static, 1) 
        for (int i = 0; i < o.num_nodes_; ++i) {
            fib(p->data_);
        }
    }

    delete head;
    double end = omp_get_wtime();

    std::cout << "Time Elapsed: " << end - start << std::endl;
    return 0;
}
