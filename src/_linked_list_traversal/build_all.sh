#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp serial/calculate.cpp -I ../auxiliaries -I serial/ -fopenmp -o ./builds/serial
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp serial/calculate.cpp -I ../auxiliaries -I serial/ -fopenmp -O2 -o ./builds/serial_O2

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1/calculate.cpp -I ../auxiliaries -I c1/ -fopenmp -o ./builds/c1
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1/calculate.cpp -I ../auxiliaries -I c1/ -fopenmp -O2 -o ./builds/c1_O2

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_1/calculate.cpp -I ../auxiliaries -I c1_1/ -fopenmp -o ./builds/c1_1
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_1/calculate.cpp -I ../auxiliaries -I c1_1/ -fopenmp -O2 -o ./builds/c1_1_O2

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_2/calculate.cpp -I ../auxiliaries -I c1_2/ -fopenmp -o ./builds/c1_2
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_2/calculate.cpp -I ../auxiliaries -I c1_2/ -fopenmp -O2 -o ./builds/c1_2_O2

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I ../auxiliaries -I c1_3/ -fopenmp -o ./builds/c1_3
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I ../auxiliaries -I c1_3/ -fopenmp -O2 -o ./builds/c1_3_O2
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I ../auxiliaries -I c1_3/ -fopenmp -fopenmp-simd -o ./builds/c1_3_simd
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I ../auxiliaries -I c1_3/ -fopenmp -fopenmp-simd -O2 -o ./builds/c1_3_O2_simd

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c2/calculate.cpp -I ../auxiliaries -I c2/ -fopenmp -o ./builds/c2
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c2/calculate.cpp -I ../auxiliaries -I c2/ -fopenmp -O2 -o ./builds/c2_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/calculate.cpp -I ../auxiliaries -I c3/ -fopenmp  -o ./builds/c3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/calculate.cpp -I ../auxiliaries -I c3/ -fopenmp -O2 -o ./builds/c3_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/calculate.cpp -I ../auxiliaries -I c3/ -fopenmp -fopenmp-simd -o ./builds/c3_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/calculate.cpp -I ../auxiliaries -I c3/ -fopenmp -O2 -fopenmp-simd -o ./builds/c3_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/calculate.cpp -I ../auxiliaries -I c3_1/ -fopenmp  -o ./builds/c3_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/calculate.cpp -I ../auxiliaries -I c3_1/ -fopenmp -O2 -o ./builds/c3_1_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/calculate.cpp -I ../auxiliaries -I c3_1/ -fopenmp -fopenmp-simd -o ./builds/c3_1_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/calculate.cpp -I ../auxiliaries -I c3_1/ -fopenmp -O2 -fopenmp-simd -o ./builds/c3_1_O2_simd

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c4/calculate.cpp -I ../auxiliaries -I c4/ -fopenmp -o ./builds/c4
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c4/calculate.cpp -I ../auxiliaries -I c4/ -fopenmp -O2 -o ./builds/c4_O2

#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c5/calculate.cpp -I ../auxiliaries -I c5/ -fopenmp -o ./builds/c5
#g++ run.cpp fibonacci.cpp ../auxiliaries/auxiliaries.cpp c5/calculate.cpp -I ../auxiliaries -I c5/ -fopenmp -O2 -o ./builds/c5_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c5/calculate.cpp -I c5/ -I ../auxiliaries/ -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c5_simd
