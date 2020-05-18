#include "auxiliaries.hpp"

void initialize_rand_arr(unsigned char *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = (unsigned char)rand() % 3;
    }
}


long long int accumulate(unsigned char *arr, size_t size) {
    long long int sum = 0.0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}
