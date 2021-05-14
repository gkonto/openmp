rm -f ./builds/*

<<COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/dprod.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/dprod.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/dprod.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -fno-inline -fno-tree-vectorize -fopenmp -O2 -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/dprod.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -fno-inline -ftree-vectorize -fopenmp -O2 -o ./builds/Alt4

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dprod.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -fno-inline -fno-tree-vectorize -fopenmp -O2 -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/dprod.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -fno-inline -ftree-vectorize -fopenmp -O2 -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/dprod.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -fno-inline -fno-tree-vectorize -fopenmp -O2 -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/dprod.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -fno-inline -ftree-vectorize -fopenmp -O2 -o ./builds/Alt8

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/dprod.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -fno-inline -fopenmp -O2 -o ./builds/Alt9

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/dprod.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -fno-inline -fopenmp -O2 -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/dprod.cpp -I c2_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -fno-inline -fopenmp -O2 -o ./builds/Alt11

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_3/dprod.cpp -I c2_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt33.log -fno-inline -fopenmp -O2 -o ./builds/Alt33

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/dprod.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt12

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/dprod.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt13.log -O2  -fno-inline -fno-stack-protector\
#    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt13

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_2/dprod.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt13.log -O2  -fno-inline -fno-stack-protector\
#    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt13

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_3/dprod.cpp -I c3_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt13

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_4/dprod.cpp -I c3_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt14

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_5/dprod.cpp -I c3_5/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt15

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_6/dprod.cpp -I c3_6/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2  -fno-inline -fno-stack-protector\
   -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt16

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_7/dprod.cpp -I c3_7/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt16

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_7_1/dprod.cpp -I c3_7_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt17.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt17

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_7_2/dprod.cpp -I c3_7_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt18.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt18

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_8/dprod.cpp -I c3_8/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt19.log -O2  -fno-inline -fno-stack-protector\
#    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt19

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_8_1/dprod.cpp -I c3_8_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt19.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt19

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_9/dprod.cpp -I c3_9/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt20.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt20

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_9_1/dprod.cpp -I c3_9_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt20.log -O2  -fno-inline -fno-stack-protector\
#    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt20

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_9_2/dprod.cpp -I c3_9_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt21.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt21

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_10/dprod.cpp -I c3_10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt22.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt22

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_11/dprod.cpp -I c3_11/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt17.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt17

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_11_1/dprod.cpp -I c3_11_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt18.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt18

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_12/dprod.cpp -I c3_12/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt19.log -O2  -fno-inline -fno-stack-protector\
#    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt19

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_14/dprod.cpp -I c3_14/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt20.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt20

COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_15/dprod.cpp -I c3_15/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt21.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt21
<<COMMENT1


COMMENT1
