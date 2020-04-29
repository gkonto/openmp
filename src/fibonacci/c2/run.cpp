#include <iostream>
#include <omp.h>
#include "fib/fib.hpp"


int main(void) {
    #pragma omp parallel 
    {
        #pragma omp single
             std::cout << fib(33) << std::endl;
    }
}
