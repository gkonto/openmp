#include <mergesort.hpp> 
#include <iostream>
#include "../common.hpp"

 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
#pragma omp task
        {
            mergeSort(arr, l, m);
        }

#pragma omp task
        {
            mergeSort(arr, m + 1, r);
        }
#pragma omp taskwait
        merge(arr, l, m, r);
    }
}

void mergeSort_wrapper(int *arr, int lhs, int rhs)
{
#pragma omp parallel
#pragma omp single
    {
        mergeSort(arr, lhs, rhs);
    }
}
 
