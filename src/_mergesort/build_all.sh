g++ ./run.cpp ./serial/mergesort.cpp -I ../auxiliaries/ -I ./serial/ --std=c++11  -o ./builds/serial
g++ ./run.cpp ./serial/mergesort.cpp -I ../auxiliaries/ -I ./serial/ --std=c++11 -O2 -o ./builds/serial_O2
