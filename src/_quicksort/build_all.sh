rm -f builds/*
<<COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/qsort.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/qsort.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2


#g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/qsort.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/qsort.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/qsort.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/qsort.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4


g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/qsort.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/qsort.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4


g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/qsort.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/qsort.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/qsort.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/qsort.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8
<<COMMENT2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/qsort.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt9
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/qsort.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/qsort.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -fno-stack-protector -O2 -fno-inline -fno-tree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/qsort.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -fno-stack-protector -O2 -fno-inline -ftree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_2/qsort.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_2/qsort.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_3/qsort.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_3/qsort.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_4/qsort.cpp -I c3_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_4/qsort.cpp -I c3_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -foffload=nvptx-none="-O2" -o ./builds/Alt10

g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/serial
g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/serial_O2

g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c1
g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c1_O2

g++ run.cpp c1_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1_1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c1_1
g++ run.cpp c1_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1_1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c1_1_O2

g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O0 -Wall -Wextra -o builds/c2
g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O2 -Wall -Wextra -o builds/c2_O2

g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c2_1
g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c2_1_O2

g++ run.cpp c2_2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_2 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c2_2
g++ run.cpp c2_2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_2 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c2_2_O2

g++ run.cpp c3/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c3 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c3
g++ run.cpp c3/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c3 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c3_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4_O2
COMMENT2
