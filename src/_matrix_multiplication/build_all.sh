rm -f ./builds/*

<<COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp serial/matmul.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp serial/matmul.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1/matmul.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1/matmul.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1_1/matmul.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1_1/matmul.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c2_1/matmul.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c2_1/matmul.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c2_1/matmul.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fopenmp -fno-inline -fopenmp-simd -o ./builds/Alt9

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/matmul.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt10
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/matmul.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-tree-vectorize -fopenmp -fno-inline -o ./builds/Alt11

COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_3/matmul.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt12
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_3/matmul.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-tree-vectorize -fopenmp -fno-inline -o ./builds/Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_3/matmul.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fopenmp -fno-inline -o ./builds/Alt14
<<COMMENT2

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_4/matmul.cpp -I c3_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt15
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_4/matmul.cpp -I c3_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-tree-vectorize -fopenmp -fno-inline -o ./builds/Alt16

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_12/matmul.cpp -I c3_12/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt17.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt17
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_12/matmul.cpp -I c3_12/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt18.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-tree-vectorize -fopenmp -fno-inline -o ./builds/Alt18

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c4/matmul.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt19.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt19
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c4/matmul.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt20.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fno-tree-vectorize -fopenmp -fno-inline -o ./builds/Alt20
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c4/matmul.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt21.log -O2 -foffload=nvptx-none="-O2" -fno-stack-protector -fopenmp -fno-inline -o ./builds/Alt21
COMMENT2
