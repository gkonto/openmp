#ifndef TOOLS_HPP
#define TOOLS_HPP

double **create_matrix(int rows, int cols);
void destroy_matrix(double **&mat, int rows);
void fill_random_symmetric(double **mat, int rows, int cols);

#endif
