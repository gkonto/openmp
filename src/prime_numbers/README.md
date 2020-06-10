# Prime Numbers

Each folder contains a variation of Prime Number calculation.
To run tests and compare their output, follow the instructions below:

0. Compile all variations by executing [./setup.py](./setup.py) script.
> This script compiles all problem variations by creating a ./build folder 
  in each variation and calling the correponding make functions.
1. [./run_test.py](./run_test.py)
> A .json file will be produced.
> run_test.py script uses run_variations.json file.

> The file run_variations.json contains test cases for each variation in a specific format.

> It is a list of entries where each entry is a unique run.

> The entry is a list where first index is the variation (eg sequential or c1 etch) and the second argument is a list 

2. [./create_graph.py](./create_graph.py)
> A graph will be created based on the .json file


