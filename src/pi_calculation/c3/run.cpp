#include <iostream>
#include <omp.h>
#include "integrate/integ.hpp"

// Example on page 52

int main(void) {
    auto seconds = omp_get_wtime();
    double p = pi();
    std::cout << omp_get_wtime() - seconds << std::endl;
    if (abs(p - 3.1415) > 0.001) {
        return 1;
    }
    return 0;
}
