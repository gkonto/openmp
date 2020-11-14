#include <iostream>
#include "qsort.hpp"


/* COMMENT
 * partition is not thread safe
 */

// Function to  partition the array on the basis of pibot element.
int partition(int array[], int low, int high) 
{
	//select picot element

	int pivot = array[high];
	int i = (low - 1);

	// Put the elements smaller  than pivot on the left
	// and greater than pivot  on the right of pivot.
#pragma omp parallel for firstprivate(i) lastprivate(i)
	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {
#pragma omp critical 
			{
				++i;
                std::swap(array[i], array[j]);
			}
		}
	}
	std::swap(array[i + 1], array[high]);
	return (i + 1);
}


void qsort(int array[], int low, int high)
{
	if (low < high) {
		int pi = partition(array, low, high);
		qsort(array, low, pi - 1);

		qsort(array, pi + 1, high);
	}
}



void qsort_wrapper(int array[], int low, int high)
{
    qsort(array, low, high);
}
