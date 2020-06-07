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

void merge(int * X, int n, int * tmp) {
   int i = 0;
   int j = n/2;
   int ti = 0;

   while (i<n/2 && j<n) {
      if (X[i] < X[j]) {
         tmp[ti] = X[i];
         ti++; i++;
      } else {
         tmp[ti] = X[j];
         ti++; j++;
      }
   }
   while (i<n/2) { /* finish up lower half */
      tmp[ti] = X[i];
      ti++; i++;
   }
      while (j<n) { /* finish up upper half */
         tmp[ti] = X[j];
         ti++; j++;
   }
   memcpy(X, tmp, n*sizeof(int));

} // end of merge()

void mergesort_seq(int *X, int n, int *tmp) {
    if (n == 2) {
        if (X[0] <= X[1]) {
            return;
        } else {
            int t = X[0];
            X[0] = X[1];
            X[1] = t;
            return;
        }
    }
    mergesort_seq(X, n/2, tmp);
    mergesort_seq(X + n/2, n - n/2, tmp);
    merge(X, n, tmp);
}

void mergesort_par(int * X, int n, int * tmp, int threads)
{
    if (threads == 1) {
        mergesort_seq(X, n, tmp);
    } else if (threads > 1) {
            #pragma omp parallel sections
            {
#pragma omp section
                mergesort_par(X, n/2, tmp, threads/2);
#pragma omp section
                mergesort_par(X + n/2, n - n/2, tmp + n/2, threads - threads/2);
            }
            merge(X, n, tmp);
        }
    }
}

namespace { 
    struct Opts {
        int size;
        int num_threads;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 3) {
        std::cout << "Specify array size and number of threads" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.size);
    read_value<int>(argv[2], o.num_threads);
}

int main(int argc, char **argv)
{
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

   mergesort_par(data, n, tmp, o.num_threads);

   stop = omp_get_wtime();
   printf("\nList After Sorting...\n");
//   print_list(data, n);
   printf("\nExecution Time: %g seconds\n",stop-start);
   delete []data;
   delete []tmp;
}


