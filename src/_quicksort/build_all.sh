g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -O0 -o builds/serial
g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -O2 -o builds/serial_O2

g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -O0 -o builds/c1
g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -O2 -o builds/c1_O2

g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O0 -o builds/c2
g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O2 -o builds/c2_O2

g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -O0 -o builds/c2_1
g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -O2 -o builds/c2_1_O2
