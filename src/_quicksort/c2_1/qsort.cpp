#include "qsort.hpp"

// Function to  partition the array on the basis of pibot element.
size_t partition(int array[], size_t low, size_t high) 
{
	//select picot element
	size_t pivot = array[high];
	size_t i = (low - 1);

	// Put the elements smaller  than pivot on the left
	// and greater than pivot  on the right of pivot.
#pragma omp parallel for 
	for (size_t j = low; j < high; j++) {
		if (array[j] <= pivot) {
			++i;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return (i + 1);
}


void qsort(int array[], size_t low, size_t high)
{
	if (low < high) {
		size_t pi = partition(array, low, high);
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


void qsort_wrapper(int array[], size_t low, size_t high)
{
#pragma omp single
    {
        qsort(array, 0, high);
    }
}


