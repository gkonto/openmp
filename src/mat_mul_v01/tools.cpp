#include <stdlib.h>
#include "tools.hpp"
#include <stdio.h>


// Each element is assigned the loop iteration number.
void fill_array(int *arr, size_t size) {
    for (size_t k = 0; k < size; ++k) {
	    arr[k] = static_cast<int>(k);
    }
}


void verify(int *arr, size_t size) {
	for (size_t k = 0; k < size; ++k) {
		if (arr[k] != k * 2) {
			printf("Error in position %ld. Got %d, expected %ld\n",
				       	k, arr[k], k * 2);
			exit(1);
		}
	}
}


