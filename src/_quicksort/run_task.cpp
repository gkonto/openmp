/*
Ο Quicksort αλγοριθός αποτελεί ένα καλό παραδειγμα του πως 
πως μπορει να παραλληλοποιηθεί ένας αλγόριθμός divide and conquer.
Στην απλούστερη του μορφή, συνηθως εκφράζεται ως αναδρομική fork-join μοντελο.
Πιο περίπλοκες παραλλαγές περιλαμβάνουν αποτελούν μόνο μερική αναδρομή

Ο σειριακός αλγόριθμός ταξινομεί μια σειρά απο αντικείμενα με αναδρομικό τμηματισμό,
	σύμφωνα με τον παρακάτω ψευδοκώδικα

	void Quicksort(sequence) {
		if (sequence is short) {
			
		} else {
			//Divide
			Choose a partition key K from the sequence
			Permute the sequence such as that:
				Keys to the left of k are less than K
				Keys to the right of k are greater than K
			//COnquer
			Recursibely sort the subsequence to the left of K
			Recursively sort the subsequence to the right of K
		}
	}
Τα δυο τμήματα ταξινομήσεων ειναι ανεξαρτητα μεταξύ τους και μπορουν να γίνουν παραλληλα.
*/

#include <iostream>
#include "qsort.hpp"
#include "auxiliaries.hpp"
#include <iomanip>
#include <cstdlib>
#include "omp.h"

using namespace std;

namespace {
	struct Opts {
		size_t size = 0;
	};
}

void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify array size!" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.size);
}


static void fill_random_arr(int *arr, size_t size) {
//#pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = (int)(rand());
    }
}

void printArray(int array[], int size) {
	int i = 0;
	for (i = 0; i < size; ++i) {
		std::cout << array[i] << " " << std::endl;
	}
}

// Driver code
int main(int argc, char **argv) {
	Opts o;
	parseArgs(argc, argv, o);
	int *a = new int[o.size];
	fill_random_arr(a, o.size);



	//int data[] = {8, 7, 6, 1, 0, 9, 2};
	//int n = sizeof(data) / sizeof(data[0]);
	//printArray(a, o.size);
	auto start = omp_get_wtime();
#pragma omp single
	{
		qsort(a, 0, o.size - 1);
	}
	auto end = omp_get_wtime();
	std::cout << "Execution time: " << std::fixed << end-start << 
		std::setprecision(5);
	std::cout << " sec " << std::endl;

	cout << "Sorted array in ascending order: \n";
	printArray(a, o.size);
	delete []a;
}
