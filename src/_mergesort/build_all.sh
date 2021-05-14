rm -f ./builds/*

<<COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp serial/mergesort.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp serial/mergesort.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1/mergesort.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1/mergesort.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_1/mergesort.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_1/mergesort.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_2/mergesort.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_2/mergesort.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_3/mergesort.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_3/mergesort.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_4/mergesort.cpp -I c1_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_4/mergesort.cpp -I c1_4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8

#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_5/mergesort.cpp -I c1_5/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt9
#g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_5/mergesort.cpp -I c1_5/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt10


g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_7/mergesort.cpp -I c1_7/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_7/mergesort.cpp -I c1_7/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_8/mergesort.cpp -I c1_8/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_8/mergesort.cpp -I c1_8/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt12

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_9/mergesort.cpp -I c1_9/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_9/mergesort.cpp -I c1_9/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt14

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_10/mergesort.cpp -I c1_10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt15
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_10/mergesort.cpp -I c1_10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt16

COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_11/mergesort.cpp -I c1_11/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt17.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt17
g++ run.cpp ../auxiliaries/auxiliaries.cpp common.cpp c1_11/mergesort.cpp -I c1_11/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt18.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt18
<<COMMENT2

COMMENT2
