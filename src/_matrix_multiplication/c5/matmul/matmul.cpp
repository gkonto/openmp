#include <iostream>
#include "matmul.hpp"

#define THRESHOLD 32768 // product size below which simple matmult code is called

static void matmult(int mf, int ml, int nf, int nl, int pf, int pl, int **A, int **B, int **&C) {

    for (int i = mf; i < ml; ++i) {
        for (int j = nf; j < nl; ++j) {
            int tmp = 0;
            for (int k = pf; k < pl; ++k) {
                tmp += A[i][k] * B[k][j];
            }
            C[i][j] = tmp;
        }
    }
}

// Dimensions: A[mf..ml][pf..pl] B[pf..pl][nf..nl] C[mf..ml][nf..nl]
void matmultrec(int mf, int ml, int nf, int nl, int pf, int pl, int **A, int **B, int **&C) {

    if ((ml-mf)*(nl-nf)*(pl-pf) < THRESHOLD) {
        matmult(mf, ml, nf, nl, pf, pl, A, B, C);
    } else {
#pragma omp task firstprivate(mf,ml,nf,nl,pf,pl)
        {
            // C11 += A11*B11
            // C11 += A12*B21
            matmultrec(mf, mf+(ml-mf)/2, nf, nf+(nl-nf)/2, pf, pf+(pl-pf)/2, A, B, C);
            matmultrec(mf, mf+(ml-mf)/2, nf, nf+(nl-nf)/2, pf+(pl-pf)/2, pl, A, B, C);
        }
#pragma omp task firstprivate(mf,ml,nf,nl,pf,pl)
        {
            // C12 += A11*B12
            // C12 += A12*B22
            matmultrec(mf, mf+(ml-mf)/2, nf+(nl-nf)/2, nl, pf, pf+(pl-pf)/2, A, B, C);
            matmultrec(mf, mf+(ml-mf)/2, nf+(nl-nf)/2, nl, pf+(pl-pf)/2, pl, A, B, C);
        }
#pragma omp task firstprivate(mf,ml,nf,nl,pf,pl)
        {
            // C21 += A21*B11
            // C21 += A22*B21
            matmultrec(mf+(ml-mf)/2, ml, nf, nf+(nl-nf)/2, pf, pf+(pl-pf)/2, A, B, C);
            matmultrec(mf+(ml-mf)/2, ml, nf, nf+(nl-nf)/2, pf+(pl-pf)/2, pl, A, B, C);
        }
#pragma omp task firstprivate(mf,ml,nf,nl,pf,pl)
        {
            // C22 += A21*B12
            // C22 += A22*B22
            matmultrec(mf+(ml-mf)/2, ml, nf+(nl-nf)/2, nl, pf, pf+(pl-pf)/2, A, B, C);
            matmultrec(mf+(ml-mf)/2, ml, nf+(nl-nf)/2, nl, pf+(pl-pf)/2, pl, A, B, C);
        }
#pragma omp taskwait
    }
}

