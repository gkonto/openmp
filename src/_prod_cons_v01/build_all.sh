rm -f ./builds/*

<<COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp serial/prod_cons.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp serial/prod_cons.cpp -I serial/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1/prod_cons.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c1/prod_cons.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c2/prod_cons.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c2/prod_cons.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6


g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3/prod_cons.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3/prod_cons.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8

COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_1/prod_cons.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_1/prod_cons.cpp -I c3_1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt10
<<COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/prod_cons.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/prod_cons.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt12


g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/prod_cons.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp tools.cpp c3_2/prod_cons.cpp -I c3_2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Altr6

COMMENT1
