rm -f ./builds/*

<<COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial/calculate.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fopenmp -o ./builds/Alt1

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/calculate.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/calculate.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Alt3

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/calculate.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt4
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/calculate.cpp -I c1_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
   -fopt-info-vec=builds/alt5.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Altr5

g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/calculate.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt6
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/calculate.cpp -I c1_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Alt7

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt8.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt8
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt9.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Alt9
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/calculate.cpp -I c1_3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -fopenmp -o ./builds/Alt10

g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/calculate.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/calculate.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Alt12

COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/calculate.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -fno-tree-vectorize -fno-inline -fopenmp -o ./builds/Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/calculate.cpp -I c2_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -ftree-vectorize -fno-inline -fopenmp -o ./builds/Alt14
<<COMMENT1
COMMENT1
