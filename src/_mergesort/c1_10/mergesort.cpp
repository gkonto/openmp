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
void mergeSort(int arr[], int l, int r, int num_task)
{

    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        if (num_task != 0) {
            mergeSort(arr, l, m, num_task);
            mergeSort(arr, l, m, num_task);
            merge(arr, l, m, r);
        } else {
            ++num_task;
#pragma omp parallel private(num_task)
            {
#pragma omp single nowait
                {
#pragma omp task mergeable
                    mergeSort(arr, l, m, num_task);

#pragma omp task mergeable
                    mergeSort(arr, m + 1, r, num_task);
                }
            }
            merge(arr, l, m, r);
        }
    }
}

void mergeSort_wrapper(int *arr, int lhs, int rhs)
{
    int num_task = 0;
    mergeSort(arr, lhs, rhs, num_task);
}
 
