#serial_O0
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1/ -o ./builds/c1
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1/ -o ./builds/c1_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_1/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_1/ -o ./builds/c1_1
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_1/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_1/ -o ./builds/c1_1_O2

