#include "fib.hpp"

int fib(int n) {
    int x = 0, y = 0;
    if (n < 2) {
        return n;
    } else {
        x = fib(n - 1);
        y = fib(n - 2);
        return x + y;
    }
}
