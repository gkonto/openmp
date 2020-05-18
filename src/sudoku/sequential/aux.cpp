#include <iostream>
#include "aux.hpp"

std::pair<int, int> GRID_FULL(16,16);

void print_grid(int grid[DIM][DIM]) {
    for (int i = 0; i < DIM; ++i) {

        std::cout << SPACE << SPACE << SPACE << SPACE << std::endl;
        std::cout << NEW_ROW << std::endl;
		for (int j = 0; j < DIM; j++)
		{
            std::cout << SPACE;
			if (BLANK == grid[i][j])
			{
                std::cout << SPACE;
			}
			else
			{
                std::cout << grid[i][j];
			}
            std::cout << SPACE;
            std::cout << LINE;
        }
    }
    std::cout << std::endl << NEW_ROW << std::endl << std::endl;
}


// Returns a boolean which indicates whether any assigned entry
// within the specified 3x3 box matches the given number. 
bool used_in_box(int grid[DIM][DIM], int box_start_rpw, int box_start_col, int num)
{
	for (int row = 0; row < BOX_DIM; row++)
		for (int col = 0; col < BOX_DIM; col++)
			if (grid[row + box_start_rpw][col + box_start_col] == num) 
			{
				return true;
			}
	return false;
}



// Returns a boolean which indicates whether any assigned entry
// in the specified row matches the given number. 
static bool used_in_row(int grid[DIM][DIM], int row, int num)
{
	for (int col = 0; col < DIM; col++)
		if (grid[row][col] == num)
		{
			return true;
		}
	return false;
}

// Returns a boolean which indicates whether any assigned entry
// in the specified column matches the given number. 
static bool used_in_col(int grid[DIM][DIM], int col, int num)
{
	for (int row = 0; row < DIM; row++)
		if (grid[row][col] == num)
		{
			return true;
		}
	return false;
}

// Returns a boolean which indicates whether it will be legal to assign
// num to the given row,col location.
bool is_safe(int grid[DIM][DIM], int row, int col, int num)
{
	// Check if 'num' is not already placed in current row,
	// current column and current 3x3 box
	return !used_in_row(grid, row, num) &&
		!used_in_col(grid, col, num) &&
		!used_in_box(grid, row - row % BOX_DIM, col - col % BOX_DIM, num);
}



// Searches the grid to find an entry that is still unassigned. If
// found, the reference parameters row, col will be set the location
// that is unassigned, and true is returned. If no unassigned entries
// remain, false is returned.
std::pair<int, int> get_unassigned_location(int grid[DIM][DIM])
{
	for (int row = 0; row < DIM; row++) {
		for (int col = 0; col < DIM; col++) {
			if (grid[row][col] == BLANK)
			{
				return std::make_pair(row, col);
			}
        }
    }

	return GRID_FULL;
}



// Takes a partially filled-in grid and attempts to assign values to
// all unassigned locations in such a way to meet the requirements
// for Sudoku solution (non-duplication across rows, columns, and boxes) 
bool solve_sudoku(int grid[DIM][DIM])
{
	// If the Soduko grid has been filled, we are done
	if (GRID_FULL == get_unassigned_location(grid))
	{
        std::cout << "Vgainei apo edo" << std::endl;
		return true; 
	}
    std::cout << "Sinexizei" << std::endl;

	// Get an unassigned Soduko grid location
	std::pair<int, int> row_and_col = get_unassigned_location(grid);
	int row = row_and_col.first;
	int col = row_and_col.second;

	// Consider digits 1 to 9
	for (int num = 1; num <= BOX_DIM; num++)
	{
		// If placing the current number in the current
		// unassigned location is valid, go ahead
		if (is_safe(grid, row, col, num))
		{
			// Make tentative assignment
			grid[row][col] = num;

			// Do the same thing again recursively. If we go 
			// through all of the recursions, and in the end 
			// return true, then all of our number placements 
			// on the Soduko grid are valid and we have fully
			// solved it
			if (solve_sudoku(grid))
			{
				return true;
			}

			// As we were not able to validly go through all 
			// of the recursions, we must have an invalid number
			// placement somewhere. Lets go back and try a 
			// different number for this particular unassigned location
			grid[row][col] = BLANK;
		}
	}

	// If we have gone through all possible numbers for the current unassigned
	// location, then we probably assigned a bad number early. Lets backtrack 
	// and try a different number for the previous unassigned locations.
	return false; 
}
