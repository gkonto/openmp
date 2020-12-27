#include <mergesort.hpp> 
#include <iostream>
#include "../common.hpp"

/*
 * NOTES
 * Αυτο δε μπορω να καταλαβω γιατι δε παιζει.
 * Μπορει το merge να ενια πιο πανω αλλα ειναι μεσα σε task και εκτελείται με depend clause
 * που ορίζει οτι θα εκτελεσει μετά απο τα x kai y.
 */
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    int x, y;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

#pragma omp task depend(in: x, y)
        {
            merge(arr, l, m, r);
        }
 
        // Sort first and second halves
#pragma omp task depend(out: x)
        {
            mergeSort(arr, l, m);
        }

#pragma omp task depend(out: y)
        {
            mergeSort(arr, m + 1, r);
        }
    }
#pragma omp taskwait
}

void mergeSort_wrapper(int *arr, int lhs, int rhs)
{
#pragma omp parallel
#pragma omp single
    {
        mergeSort(arr, lhs, rhs);
    }
}
 
