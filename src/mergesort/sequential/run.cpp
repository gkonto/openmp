#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "omp.h"
#include "auxiliaries.hpp"

#define MAX_SIZE 10000000


void generate_list(int * x, int n) {
   int i,j,t;
   for (i = 0; i < n; i++)
     x[i] = i;
   for (i = 0; i < n; i++) {
     j = rand() % n;
     t = x[i];
     x[i] = x[j];
     x[j] = t;
   }
}

void print_list(int * x, int n) {
   int i;
   for (i = 0; i < n; i++) {
      printf("%d ",x[i]);
   } 
}

namespace { 
    struct Opts {
        int size;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify array size" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.size);
}

void merge(int* array, int start, int end)
{
    int middle = (start + end) / 2;
    int temp_index = 0;

    /* create a temporary array */
    int* temp = (int *)malloc(sizeof(int) * (end - start + 1));

    /* merge in sorted data from the 2 halves */
    int left = start;
    int right = middle + 1;

    /* while both halves have data */
    while((left <= middle) && (right <= end)) {
        /* if the left half value is less than right */
        if (array[left] < array[right]) {
            /* take from left */
            temp[temp_index] = array[left];
            temp_index++;
            left++;
        }
        else {
            /* take from right */
            temp[temp_index] = array[right];
            temp_index++;
            right++;
        }
    }

    /* add the remaining elements from the left half */
    while(left <= middle) {
        temp[temp_index] = array[left];
        temp_index++;
        left++;
    }

    /* add the remaining elements from the right half */
    while(right <= end) {
        temp[temp_index] = array[right];
        temp_index++;
        right++;
    }

    /* move from temp array to the original array */
    int i;
    for(i = start; i <= end; i++) {
        array[i] = temp[i - start];
    }

    /* free the temporary array */
    free(temp);
}

void merge_sort (int *a, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        merge_sort(a, start, middle);
        merge_sort(a, middle + 1, end);
        merge(a, start, end);
    }
}

int main(int argc, char **argv)
{
    Opts o;
    parseArgs(argc, argv, o);
   int n = o.size;
   double start, stop;

   int *data = new int[o.size];
   int *tmp = new int[o.size];
  
   generate_list(data, n);
   printf("List Before Sorting...\n");
   print_list(data, n);
   start = omp_get_wtime();

   merge_sort(data, 0, n);

   stop = omp_get_wtime();
   printf("\nList After Sorting...\n");
   print_list(data, n);
   printf("\nExecution Time: %g seconds\n",stop-start);
   delete []data;
   delete []tmp;
}


