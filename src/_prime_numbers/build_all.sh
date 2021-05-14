rm -f ./builds/*

<<COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/prime.cpp -I sequential/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/prime.cpp -I sequential/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2
COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/prime.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/prime.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

<<COMMENT3


g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/prime.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/prime.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fopenmp -o ./builds/Alt9

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt10
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -fopenmp -o ./builds/Alt12

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt14
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2 -fno-inline -fopenmp -o ./builds/Alt15

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt16.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt16
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt17.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt17
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt18.log -O2 -fno-inline -fopenmp -o ./builds/Alt18

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/prime.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt16


g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/prime.cpp -I c4_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt17.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt17

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/prime.cpp -I c4_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt18.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt18

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_6/prime.cpp -I c4_6/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt19.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt19


g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_8/prime.cpp -I c4_8/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt20.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt20

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_9/prime.cpp -I c4_9/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt21.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt21

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_10/prime.cpp -I c4_10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt22.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt22
COMMENT3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_11/prime.cpp -I c4_11/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt22.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt22
<<COMMENT2
COMMENT2

