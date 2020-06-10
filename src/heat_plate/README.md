# Heated Plate

A C++ program which solves the steady state heat equation in a 2D rectangular region.
The physical region, and the boundary conditions, are suggested by this diagram:

                   W = 0
             +------------------+
             |                  |
    W = 100  |                  | W = 100
             |                  |
             +------------------+
                   W = 100
      

The region is covered with a grid of M by N nodes, and an N by N array W is used to record the temperature.<br />
The correspondence between array indices and locations in the region is suggested by giving the indices of the four corners:

                  I = 0
          [0][0]-------------[0][N-1]
             |                  |
      J = 0  |                  |  J = N-1
             |                  |
        [M-1][0]-----------[M-1][N-1]
                  I = M-1
      

The steady state solution to the discrete heat equation satisfies the following condition at an interior grid point:

    W[Central] = (1/4) * ( W[North] + W[South] + W[East] + W[West] ) 

where "Central" is the index of the grid point, "North" is the index of its immediate neighbor to the "north", and so on.

Given an approximate solution of the steady state heat equation,<br />
a "better" solution is given by replacing each interior point by the average of its 4 neighbors - in other words,
<br />by using the condition as an ASSIGNMENT statement:

    > W[Central] <= (1/4) * ( W[North] + W[South] + W[East] + W[West] ) 

If this process is repeated often enough,<br />
the difference between successive estimates of the solution will go to zero.

This program carries out such an iteration, <br />
using a tolerance specified by the user, <br />
and writes the final estimate of the solution to a file that can be used for graphic processing.


Each folder contains a variation of Heated Plate program.
To run tests and compare their output, follow the instructions below:

0. Compile all variations by executing [./setup.py](./setup.py) script.
> This script compiles all problem variations by creating a ./build folder 
  in each variation and calling the correponding make functions.
1. [./run_test.py](./run_test.py)
> A .json file will be produced.
> run_test.py script uses run_variations.json file.<br />
> The file run_variations.json contains test cases for each variation in a specific format.<br />
> It is a list of entries where each entry is a unique run.<br />
> The entry is a list where first index is the variation (eg sequential or c1 etch) and the second argument is a list<br />
2. [./create_graph.py](./create_graph.py)
> A graph will be created based on the .json file

