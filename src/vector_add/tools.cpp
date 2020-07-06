#include <stdlib.h>
#include "tools.hpp"


void fill_random_arr(short *arr, size_t size) {
    for (size_t k = 0; k < size; ++k) {
        arr[k] = short(rand() % 100 + 1);
    }
}


