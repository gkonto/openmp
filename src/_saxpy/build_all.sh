rm -f builds/*
<<COMMENT2
# Serial
#Alt1
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial_/saxpy.cpp -I serial_/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt1.log -fno-inline -fno-tree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt1

#Alt2
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial_/saxpy.cpp -I serial_/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt2.log -fno-inline -ftree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt2
#Alt3
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial_/saxpy.cpp -I serial_/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt3.log -fno-inline -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt3



#Alt4
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/saxpy.cpp -I c1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/vec_no_info.log -fno-inline -fno-tree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/alt4

#Alt5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/saxpy.cpp -I c1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/vec_info.log -fno-inline -ftree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/alt5


#Alt6
g++ run_padding_struct.cpp ../auxiliaries/auxiliaries.cpp c1_1/saxpy.cpp -I c1_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/vec_no_info.log -fno-inline -fno-tree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt6
#Alt7
g++ run_padding_struct.cpp ../auxiliaries/auxiliaries.cpp c1_1/saxpy.cpp -I c1_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/vec_info.log -fno-inline -ftree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt7

#Alt8
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt7.log -fno-inline -fno-tree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt8
#Alt9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt8.log -fno-inline -ftree-vectorize -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt9
#Alt10
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt9.log -fno-inline  -fopenmp -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt10

#Alt11
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_0_1/saxpy.cpp -I c2_0_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt11.log -fno-inline -fno-tree-vectorize -fopenmp -fopenmp-simd  -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt11
#Alt12
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_0_1/saxpy.cpp -I c2_0_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt12.log -fno-inline -ftree-vectorize -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt12
#Alt13
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_0_1/saxpy.cpp -I c2_0_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt13.log -fno-inline -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt13

#Alt14
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt14.log -fno-inline -fno-tree-vectorize -fopenmp -fopenmp-simd  -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt14
#Alt15
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt15.log -fno-inline -ftree-vectorize -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt15
#Alt16
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt16.log -fno-inline -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt16

#Alt17
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt17.log -fno-inline -fno-tree-vectorize -fopenmp -fopenmp-simd  -Wall  -Wextra -std=c++14 -O2 -o ./builds/Alt17
#Alt18
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt18.log -fno-inline -ftree-vectorize -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt18
#Alt19
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/\
    -fopt-info-vec=builds/alt19.log -fno-inline -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/Alt19


# c3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c3
# c3  simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -o ./builds/c3_simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -fno-tree-vectorize -o ./builds/c3_simd_no_vector

# c3 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O3 -o ./builds/c3_O3
# c3 --std=c++14 -O2 -fopenmp-simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O3 -o ./builds/c3_O3_simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -fno-tree-vectorize -O3 -o ./builds/c3_O3_simd_no_vector

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/saxpy.cpp -I c4_1/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt20.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt20
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/saxpy.cpp -I c4_1/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt21.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt21


g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt22.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt22
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt23.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt23
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt24.log -O2  -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2  -fno-inline" -fopenmp -o ./builds/Alt24

# c4_1_1

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_2/saxpy.cpp -I c4_1_2/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt25.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt25
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_2/saxpy.cpp -I c4_1_2/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt26.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt26

COMMENT2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt27.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt27
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt28.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt28
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt29.log -O2 -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt29
<<COMMENT1

# c4_1_4
# c4_1_5
# c4_1_6

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/saxpy.cpp -I c4_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt30.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt30
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/saxpy.cpp -I c4_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt31.log -O2 -fno-inline -fno-stack-protector -ftree-vectorize\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt31

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_0/saxpy.cpp -I c4_3_0/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt32.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt32
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_0/saxpy.cpp -I c4_3_0/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt33.log -O2 -fno-inline -fno-stack-protector -ftree-vectorize\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt33

# c4_3_1
# c4_3_2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_3/saxpy.cpp -I c4_3_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt34.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt34

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_3/saxpy.cpp -I c4_3_3/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt35.log -O2 -fno-inline -fno-stack-protector -ftree-vectorize\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt35



g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt36.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt36
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt37.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt37
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt38.log -O2 -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt38

# c4_3_5
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_5
# c4_3_5 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O3 -fopenmp-simd" --std=c++14 -O3 -fopenmp -Wall -Wextra -o ./builds/c4_3_5_O3


g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt39.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt39
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt40.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt40
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt41.log -O2 -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt41

g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt39.log -O2 -fno-tree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-tree-vectorize -fno-inline" -fopenmp -o ./builds/Alt42
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt40.log -O2 -ftree-vectorize -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -ftree-vectorize -fno-inline" -fopenmp -o ./builds/Alt43
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -Wall -Wextra\
    -fopt-info-vec=builds/alt41.log -O2 -fno-inline -fno-stack-protector\
    -foffload=nvptx-none="-O2 -fno-inline" -fopenmp -o ./builds/Alt44
COMMENT1

