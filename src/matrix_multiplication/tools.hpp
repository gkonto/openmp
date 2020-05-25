#ifndef TOOLS_HPP
#define TOOLS_HPP

int **create_matrix(int rows, int cols);
void destroy_matrix(int **&mat, int rows);
void fill_random(int **mat, int rows, int cols);

#endif
