#ifndef TOOLS_HPP
#define TOOLS_HPP

int **create_matrix(int rows, int cols);
void destroy_matrix(int **&mat, int rows);
void fill_random(int **mat, int rows, int cols);
void fill_random_1d(int *mat, int width, int height);
void verify(int **a, int **b, int **c, int d1, int d2, int d3);
void verify_1d(int *a, int *b, int *c, int d1, int d2, int d3);
void show_matrix_1d(int *m, int d1, int d2);

#endif
