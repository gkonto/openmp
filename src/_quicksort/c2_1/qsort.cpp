#include "qsort.hpp"

// Function to  partition the array on the basis of pibot element.
int partition(int array[], int low, int high) 
{
	//select picot element
	int pivot = array[high];
	int i = (low - 1);

	// Put the elements smaller  than pivot on the left
	// and greater than pivot  on the right of pivot.
#pragma omp parallel for 
	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {
			++i;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return (i + 1);
}


void qsort(int array[], int low, int high)
{
	if (low < high) {
		int pi = partition(array, low, high);
#pragma omp task
		{
			qsort(array, low, pi - 1);
		}
#pragma omp task

		{
			qsort(array, pi + 1, high);
		}
	}
}


void qsort_wrapper(int array[], int low, int high)
{
#pragma omp parallel
#pragma omp single
    {
        qsort(array, 0, high);
    }
}


