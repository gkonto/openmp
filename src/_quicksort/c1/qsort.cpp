#include <iostream>
#include "qsort.hpp"

/* COMMENT
 * partition is not thread safe! 
 */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

#pragma omp parallel for 
	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) 
		{ 
#pragma omp critical
            {
                i++; // increment index of smaller element 
                std::swap(arr[i], arr[j]); 
            } 
        } 
    }
    std::swap(arr[i + 1], arr[high]); 
	return (i + 1); 
}

void qsort(int array[], int low, int high)
{
	if (low < high) {
		size_t pi = partition(array, low, high);
		qsort(array, low, pi - 1);
		qsort(array, pi + 1, high);
	}
}



void qsort_wrapper(int array[], int low, int high)
{
    qsort(array, low, high);
}
