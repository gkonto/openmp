rm -f ./builds/*

<<COMMENT1
g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/integ.cpp -I sequential/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt1.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/integ.cpp -I sequential/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt2.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/integ.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt3.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/integ.cpp -I c1/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt4.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt4

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/integ.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/integ.cpp -I c2/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/integ.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt5.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/integ.cpp -I c3/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt6.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/integ.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt7.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt7
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/integ.cpp -I c4/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt8log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt8

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c5/integ.cpp -I c5/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt11
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c5/integ.cpp -I c5/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
#    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt12

g++ run.cpp ../auxiliaries/auxiliaries.cpp c6/integ.cpp -I c6/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt9.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c6/integ.cpp -I c6/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt10.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt10
g++ run.cpp ../auxiliaries/auxiliaries.cpp c6/integ.cpp -I c6/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt11.log -O2 -fno-inline -fopenmp -o ./builds/Alt11


g++ run.cpp ../auxiliaries/auxiliaries.cpp c7/integ.cpp -I c7/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -fno-stack-protector\
    -fopenmp -foffload=nvptx-none="-O2 -fno-inline" -o ./builds/Alt14

g++ run.cpp ../auxiliaries/auxiliaries.cpp c8/integ.cpp -I c8/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt12.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt12

g++ run.cpp ../auxiliaries/auxiliaries.cpp c9/integ.cpp -I c9/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt13.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt13
COMMENT1

g++ run.cpp ../auxiliaries/auxiliaries.cpp c10/integ.cpp -I c10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt14.log -O2 -fno-inline -fno-tree-vectorize -fopenmp -o ./builds/Alt14
g++ run.cpp ../auxiliaries/auxiliaries.cpp c10/integ.cpp -I c10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt15.log -O2 -fno-inline -ftree-vectorize -fopenmp -o ./builds/Alt15
g++ run.cpp ../auxiliaries/auxiliaries.cpp c10/integ.cpp -I c10/ -I ../auxiliaries/ -Wall -Wextra -std=c++14\
    -fopt-info-vec=builds/alt16.log -O2 -fno-inline -fopenmp -o ./builds/Alt16
<<COMMENT2
COMMENT2
