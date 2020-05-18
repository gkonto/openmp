#include <iostream>
#include "aux.hpp"

enum {
    A = 10,
    B,
    C,
    D,
    E,
    F,
    G
} LETTERS;

int main()
{
    std::cout << "********************************\n\n\tSudoku Solver\n\n********************************" << std::endl << std::endl;

	int grid[DIM][DIM] = { 
        {0, 1, 0, 3, D, 4, 6, 5, 0, 0, 0, B, 0, C, 2, F},
        {2, 0, 9, 0, B, 0, 0, 1, 6, 0, 0, 0, 0, G, A, 0},
        {0, F, 0, 8, 0, 0, 0, A, 5, 7, D, 0, 3, 0, 6, 9},
        {6, 0, 4, A, 0, C, 0, 0, G, 3, 0, 0, 0, 5, 0, E},
        {E, A, 7, F, 0, 0, 0, 6, B, 9, 5, 3, D, 0, C, 0},
        {0, 0, 0, B, E, 0, 0, G, 0, 6, 8, 0, 0, 0, F, 0},
        {0, 0, 5, 0, 3, 9, 2, 0, C, 0, 1, F, 0, E, 0, 0},
        {8, 9, 0, 0, 0, A, F, 0, 0, D, 0, E, 0, 0, 3, 6},
        {D, 3, C, 2, 1, 0, 5, 0, 4, 0, 0, 0, 6, F, 0, 0},
        {0, 0, E, 0, 0, 3, A, 0, 8, 0, 0, 7, 0, 0, 0, 5},
        {F, 0, 6, 0, 9, 0, B, D, 1, 0, C, 0, 2, 3, 0, 4},
        {0, 0, A, 4, 6, F, 0, 0, 0, E, 0, 0, 9, 0, 0, 0},
        {3, E, F, 0, 0, 0, 0, 9, D, 0, 0, 0, 0, A, 4, 0},
        {0, 7, 0, 0, F, 0, 0, 2, 3, 8, 0, 5, E, D, 0, C},
        {A, 2, 8, 0, 0, 0, G, 0, F, C, B, 0, 1, 7, 9, 3},
        {0, 0, 0, 0, A, 7, 1, 0, 0, 0, 9, G, F, 0, 0, 0}
    };

	print_grid(grid);

	if (true == solve_sudoku(grid))
	{
		print_grid(grid);
	}
	else
	{
        std::cout << "No solution exists for the given Soduko" << std::endl << std::endl;
	}

	return 0;
}
