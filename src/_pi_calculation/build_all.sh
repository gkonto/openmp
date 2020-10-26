g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/integ.cpp -I sequential -I ../auxiliaries/ -O0 -fopenmp -o ./builds/serial_O0
g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/integ.cpp -I sequential -I ../auxiliaries/ -O2 -fopenmp -o ./builds/serial_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/integ.cpp -I c1 -I ../auxiliaries/ -O0 -fopenmp -o ./builds/c1_O0
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/integ.cpp -I c1 -I ../auxiliaries/ -O2 -fopenmp -o ./builds/c1_O2

