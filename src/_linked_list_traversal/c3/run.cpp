#include <iostream>
#include <omp.h>
#include <vector>
#include "tools/l_list.hpp"
#include "auxiliaries.hpp"

#define FIBVAL 33

struct Opts {
    int num_nodes_ = 0;
};

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify number of linked list nodes and num of threads" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.num_nodes_);
}


#pragma omp declare target
static int fib(int n);
#pragma omp end declare target


#pragma omp declare target
static int fib(int n) {
    int x = 0, y = 0;
    if (n < 2) {
        return n;
    } else {
        x = fib(n - 1);
        y = fib(n - 2);
        return x + y;
    }
}
#pragma omp end declare target

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    Node *head = init_nodes(o.num_nodes_, FIBVAL);

    double start = omp_get_wtime();
    Node *p = head;
    while (p) {
	    int i = 0;
    #pragma omp target map(from: i) map(to: p)
	    {

		    i =  fib(33);
	    }
	
	p = p->next_;
    }
    double end = omp_get_wtime();

    delete head;
    std::cout << "Time Elapsed: " << end - start << std::endl;
    return 0;
}
