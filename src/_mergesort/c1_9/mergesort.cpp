#include <mergesort.hpp> 
#include <iostream>
#include "../common.hpp"
#include <omp.h>

/*
 * NOTES
 * I moni diafora me to c1_7 einai oti exei mergeable clause
 */
int LIMIT = omp_get_num_threads();
int num_rec = 0;

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
#pragma omp critical
    {
        ++num_rec;
    }

    int x, y;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        if (num_rec > 1) {
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        } else {
            // Sort first and second halves
#pragma omp task final(num_rec > LIMIT) mergeable
            {
                mergeSort(arr, l, m);
            }

#pragma omp task final(num_rec > LIMIT) mergeable
            {
                mergeSort(arr, m + 1, r);
            }
#pragma omp taskwait
            {
                merge(arr, l, m, r);
            }
        }
    }
}

void mergeSort_wrapper(int *arr, int lhs, int rhs)
{
#pragma omp parallel
#pragma omp single nowait
    {
        mergeSort(arr, lhs, rhs);
    }
}
 
