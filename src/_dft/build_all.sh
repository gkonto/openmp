rm -f ./builds/*

<<COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/dft.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/dft.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/dft.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/dft.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4


g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dft.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dft.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/dft.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/dft.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/dft.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/dft.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/dft.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fopenmp -o ./builds/Alt9

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/dft.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt10
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/dft.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/dft.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -fopenmp -o ./builds/Alt12

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/dft.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#-fopt-info-vec=builds/alt13.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt13
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/dft.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt14
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/dft.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2 -fno-inline -fopenmp -o ./builds/Alt15

COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/dft.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -fno-inline -fno-stack-protector -foffload=nvptx-none="-O2" -fno-tree-vectorize -fopenmp -o ./builds/Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/dft.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -fno-stack-protector  -foffload=nvptx-none="-O2" -ftree-vectorize -fopenmp -o ./builds/Alt14
<<COMMENT2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dft.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dft.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

#g++ run.cpp ./serial/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I serial -fopenmp -Wall -Wextra -o ./builds/serial
#g++ run.cpp ./serial/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I serial -fopenmp -Wall -Wextra -O2 -o ./builds/serial_O2
#
#g++ run.cpp ./c1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1 -Wall -Wextra -fopenmp -o ./builds/c1
#g++ run.cpp ./c1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1 -Wall -Wextra  -fopenmp -O2 -o ./builds/c1_O2

#g++ run.cpp ./c1_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_1 -Wall -Wextra --std=c++14 -fopenmp -o ./builds/c1_1
#g++ run.cpp ./c1_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_1 -Wall -Wextra --std=c++14 -fopenmp -O2 -o ./builds/c1_1_O2

#g++ run.cpp ./c1_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_2 -Wall -Wextra --std=c++14 -fopenmp -o ./builds/c1_2
#g++ run.cpp ./c1_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_2 -Wall -Wextra --std=c++14 -fopenmp -O2 -o ./builds/c1_2_O2

#g++ run.cpp ./c1_3/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_3 -Wall -Wextra --std=c++14 -fopenmp -o ./builds/c1_3
#g++ run.cpp ./c1_3/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c1_3 -Wall -Wextra --std=c++14 -fopenmp -O2 -o ./builds/c1_3_O2

#g++ run.cpp ./c2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2 -Wall -Wextra -fopenmp-simd -o ./builds/c2
#g++ run.cpp ./c2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2 -Wall -Wextra  -fopenmp-simd -O2 -o ./builds/c2_O2
#
#g++ run.cpp ./c2_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2_1 -Wall -Wextra -fopenmp-simd -o ./builds/c2_1
#g++ run.cpp ./c2_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2_1 -Wall -Wextra  -fopenmp-simd -O2 -o ./builds/c2_1_O2
#
#g++ run.cpp ./c2_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2_2 -Wall -Wextra -fopenmp-simd -o ./builds/c2_2
#g++ run.cpp ./c2_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c2_2 -Wall -Wextra  -fopenmp-simd -O2 -o ./builds/c2_2_O2

#g++ run.cpp ./c3/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3 -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c3
#g++ run.cpp ./c3/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3 -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c3_O2
#
#g++ run.cpp ./c3_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3_1 -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c3_1
#g++ run.cpp ./c3_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3_1 -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c3_1_O2
#
#g++ run.cpp ./c3_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3_2 -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c3_2
#g++ run.cpp ./c3_2/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c3_2 -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c3_2_O2

#g++ run.cpp ./c4/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c4 --std=c++14 -Wall -fno-stack-protector -foffload=nvptx-none="-O2" -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c4_O2

g++ run.cpp ./c4_1/dft.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries/ -I c4_1 --std=c++14 -Wall -fno-stack-protector -foffload=nvptx-none="-O2" -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c4_1_O2

COMMENT2
