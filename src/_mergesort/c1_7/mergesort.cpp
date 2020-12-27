#include <mergesort.hpp> 
#include <iostream>
#include "../common.hpp"
#include <omp.h>

/*
 * NOTES
 * Edo prepei na paikso me to LIMIT kai na vro enan tropo na auksano to num_rec!!!
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
 
        // Sort first and second halves
#pragma omp task final(num_rec > LIMIT)
        {
            mergeSort(arr, l, m);
        }

#pragma omp task final(num_rec > LIMIT)
        {
            mergeSort(arr, m + 1, r);
        }
#pragma omp taskwait
        {
            merge(arr, l, m, r);
        }
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
 
