/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <iomanip>
#include "mergesort.hpp"
#include "auxiliaries.hpp"
#include <omp.h>

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

namespace {
    struct Opts {
        int size = 0;
        bool verify = false;
    };
}

static void parseArgs(int argc, char **argv, Opts &o)
{
    if (argc != 3) {
        std::cout << "Specify array size and verification" << std::endl;
        exit(1);
    }

    read_value<int>(argv[1], o.size);
    read_value<bool>(argv[2], o.verify);
}


static void fill_random_array(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000000;
    }
}

static void verify(int *a, int size)
{
    for (size_t i = 1; i < size; ++i) {
        if (a[i] < a[i-1]) {
            std::cout << "Verification failed! Aborinting ..." << std::endl;
            exit(1);
        }
    }

    std::cout << "Successfull verification" << std::endl;
}
 
/* Driver code */
int main(int argc, char **argv)
{
    Opts o;
    parseArgs(argc, argv, o);

    int *arr = new int[o.size];
    fill_random_array(arr, o.size);

    //int arr[] = { 12, 11, 13, 5, 6, 7 };
 
	auto start = omp_get_wtime();
    mergeSort_wrapper(arr, 0, o.size - 1);
	auto end = omp_get_wtime();
	std::cout << "Execution time: " << std::fixed <<  std::setprecision(3) << end-start << 
		std::setprecision(5) << std::endl;

    if (o.verify) {
        verify(arr, o.size);
    }
    return 0;
}
