#include <omp.h>
#include "fib.hpp"

int fib(int n) {
    int x = 0, y = 0;
    if (n < 2) {
        return n;
    } else {
#pragma omp task shared(x)
        x = fib(n - 1);
#pragma omp task shared(y)
        y = fib(n - 2);
#pragma omp taskwait
        return x + y;
    }
}
