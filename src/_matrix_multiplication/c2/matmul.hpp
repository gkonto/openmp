#ifndef MATMUL_HPP
#define MATMUL_HPP

#define SINGLE_POINTER

#ifndef SINGLE_POINTER
void matmul(int **A, int r1, int c1, int **B, int r2, int c2,
        int **&C, int &r3, int &c3);
#else
void matmul(int *a, int r1, int c1, int *b, int r2, int c2,
        int *c, int r3, int c3);
#endif

#endif
