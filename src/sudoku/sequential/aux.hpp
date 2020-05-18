#ifndef AUX_HPP
#define AUX_HPP

#include <utility>

const int DIM = 16;
const char BOX_DIM = 4;
const int BLANK = 0;
const char SPACE = ' ';
const char LINE  = '|';
const char *const NEW_ROW = "------------------------------------";


extern void print_grid(int grid[DIM][DIM]);
extern bool solve_sudoku(int grid[DIM][DIM]);

#endif
