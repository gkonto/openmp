#include <iostream>
#include <sstream>
#include "fib/fib.hpp"

static int parseArgs(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Specify fibonacci value to be calculated" << std::endl;
        exit(1);
    }
    
    char *v = argv[1];
    std::stringstream ss;
    ss << v;
    int val = 0;
    ss >> val;

    return val;
}

int main(int argc, char **argv) {
    int val = parseArgs(argc, argv);

    std::cout << fib(val) << std::endl;
}
