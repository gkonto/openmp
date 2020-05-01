#include <iostream>
#include "fib/fib.hpp"
#include "../../argparser/argparser.hpp"


int main(int argc, char **argv) {
    ArgParser parser("Sequential fibonacci execution", argc, argv);
    std::cout << fib(33) << std::endl;
}
