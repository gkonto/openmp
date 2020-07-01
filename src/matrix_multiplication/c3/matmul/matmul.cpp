#include <iostream>
#include "matmul.hpp"
#include <omp.h>


void matmul(int N, int BS, int **A, int **B, int **C)
{
    int i, j, k, ii, jj, kk;
    for (i = 0; i < N; i+=BS) {
        for (j = 0; j < N; j+=BS) {
            for (k = 0; k < N; k+=BS) {
            // Note 1: i, j, k, A, B, C are firstprivate by default
            // Note 2: A, B and C are just pointers
#pragma omp task private(ii, jj, kk) \
            depend ( in: A[i:BS][k:BS], B[k:BS][j:BS] ) \
            depend ( inout: C[i:BS][j:BS] )
                for (ii = i; ii < i+BS; ii++ )
                    for (jj = j; jj < j+BS; jj++ )
                        for (kk = k; kk < k+BS; kk++ )
                            C[ii][jj] = C[ii][jj] + A[ii][kk] * B[kk][jj];
            }
        
        }
    }
}
