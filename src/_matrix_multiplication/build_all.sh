g++ run.cpp ./sequential1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./sequential1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/serial_O0
g++ run.cpp ./sequential1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./sequential1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/serial_O2

g++ run.cpp ./c1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1_O0
g++ run.cpp ./c1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_O2

g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c2_O0
g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c2_O2

g++ run.cpp ./c3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c3_O0
g++ run.cpp ./c3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c3_O2

g++ run.cpp ./c4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c4/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c4_O0
g++ run.cpp ./c4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c4/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c4_O2
