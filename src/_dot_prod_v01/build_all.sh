#serial_O0
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial_O0
#serial_O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial_O2

c1
