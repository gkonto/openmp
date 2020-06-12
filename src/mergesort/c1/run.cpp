#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "omp.h"
#include "auxiliaries.hpp"
#include "common.hpp"

#define MAX_SIZE 10000000

namespace { 
    struct Opts {
        int size;
        int num_threads;
    };
}

void merge(int a[], int l, int m, int r) {
	int temp[m-l+1], temp2[r-m];
	//copy first part to temporary array
	for(int i=0; i<(m-l+1); i++)
		temp[i]=a[l+i];
	//copy second part to temporary arrat]y
	for(int i=0; i<(r-m); i++)
		temp2[i]=a[m+1+i];
	int i=0, j=0, k=l;
	//combine the arrays on the basis of order
	while(i<(m-l+1) && j<(r-m)) {
		if(temp[i]<temp2[j])
			a[k++]=temp[i++];
		else
			a[k++]=temp2[j++];
	}
	//to combine the remainder of the two arrays
	while(i<(m-l+1))
		a[k++]=temp[i++];
	while(j<(r-m))
		a[k++]=temp2[j++];

}


static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify array size and number of threads" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.size);
    read_value<int>(argv[2], o.num_threads);
}


void mergeSort(int a[], int l, int r) {
	if(l<r) {
		//cout<<"came here";
		int m=(l+r)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergeSort(a,l,m); //call 1
			}
			#pragma omp section
			{
				mergeSort(a,m+1,r); //call 2
			}
		}
		merge(a,l,m,r); //this function is outside the parallel sections since it merges and access the same data
	}
}

int main(int argc, char **argv) {
   Opts o;
   parseArgs(argc, argv, o);

   int n = o.size;
   omp_set_num_threads(o.num_threads);
   double start, stop;

   int *data = new int[o.size];
   int *tmp = new int[o.size];
  
   generate_list(data, n);
   printf("List Before Sorting...\n");
   print_list(data, n);
   start = omp_get_wtime();
   mergeSort(data,0,n-1);
   stop = omp_get_wtime();
   printf("\nList After Sorting...\n");
   print_list(data, n);
   printf("\nExecution Time: %g seconds\n",stop-start);
   delete []data;
   delete []tmp;
}


