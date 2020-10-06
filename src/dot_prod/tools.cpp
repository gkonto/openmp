#include <stdlib.h>
#include "tools.hpp"


void fill_random_arr(int *arr, int *arr2, size_t size) {
#pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = k;//int(rand() % 20 -10 );
        arr2[k] = k;//int(rand() % 20 -10 );
    }
}


