#g++ run.cpp ./serial/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./serial/ -I ../auxiliaries -Wextra -Wall --std=c++14 -O0 -fopenmp -o ./builds/serial
#g++ run.cpp ./serial/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./serial/ -I ../auxiliaries -Wextra -Wall --std=c++14 -O2 -fopenmp -o ./builds/serial_O2

#g++ run.cpp ./c1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1
#g++ run.cpp ./c1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_O2

#g++ run.cpp ./c1_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1_1
#g++ run.cpp ./c1_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_1_O2

#g++ run.cpp ./c1_2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_2/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1_2
#g++ run.cpp ./c1_2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_2/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_2_O2

#g++ run.cpp ./c1_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_3/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1_3
#g++ run.cpp ./c1_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_3/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_3_O2

#g++ run.cpp ./c1_4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_4/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c1_4
#g++ run.cpp ./c1_4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c1_4/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c1_4_O2

#g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c2
#g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c2_O2
#g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -fopenmp-simd -o ./builds/c2_simd
#g++ run.cpp ./c2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -fopenmp-simd -o ./builds/c2_O2_simd

#g++ run.cpp ./c2_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2_1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c2_1
#g++ run.cpp ./c2_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2_1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c2_1_O2
#g++ run.cpp ./c2_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2_1/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -fopenmp-simd -o ./builds/c2_1_simd
#g++ run.cpp ./c2_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c2_1/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -fopenmp-simd -o ./builds/c2_1_O2_simd
#
#g++ run.cpp ./c3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3
#g++ run.cpp ./c3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_O2

#g++ run.cpp ./c3_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_1/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_1
#g++ run.cpp ./c3_1/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_1/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_1_O2

#g++ run.cpp ./c3_2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_2/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_2
#g++ run.cpp ./c3_2/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_2/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_2_O2

#g++ run.cpp ./c3_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_3
#g++ run.cpp ./c3_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_3_O2
#g++ run.cpp ./c3_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -fopenmp-simd -o ./builds/c3_3_simd
#g++ run.cpp ./c3_3/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_3/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -fopenmp-simd -o ./builds/c3_3_O2_simd

#g++ run.cpp ./c3_4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_4/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_4
#g++ run.cpp ./c3_4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_4/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_4_O2
#
#g++ run.cpp ./c3_5/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_5/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_5
#g++ run.cpp ./c3_5/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_5/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_5_O2
#g++ run.cpp ./c3_5/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_5/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -fopenmp-simd -o ./builds/c3_5_simd
#g++ run.cpp ./c3_5/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_5/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -fopenmp-simd -o ./builds/c3_5_O2_simd

#g++ run.cpp ./c3_6/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_6/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_6
#g++ run.cpp ./c3_6/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_6/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_6_O2

#g++ run.cpp ./c3_7/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_7/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_7
#g++ run.cpp ./c3_7/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_7/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_7_O2

#g++ run.cpp ./c3_8/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_8/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_8
#g++ run.cpp ./c3_8/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_8/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_8_O2
#
#g++ run.cpp ./c3_9/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_9/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_9
#g++ run.cpp ./c3_9/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_9/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_9_O2

#g++ run.cpp ./c3_10/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_10/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_10
#g++ run.cpp ./c3_10/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_10/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_10_O2

#g++ run.cpp ./c3_11/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_11/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_11
#g++ run.cpp ./c3_11/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_11/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_11_O2

#g++ run.cpp ./c3_12/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_12/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_12
#g++ run.cpp ./c3_12/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_12/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_12_O2

g++ run.cpp ./c3_13/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_13/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O0 -fopenmp -o ./builds/c3_13
g++ run.cpp ./c3_13/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c3_13/ -I ../auxiliaries -fno-stack-protector -foffload=nvptx-none -Wall -Wextra --std=c++14 -O2 -fopenmp -o ./builds/c3_13_O2
#
#g++ run.cpp ./c4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c4/ -I ../auxiliaries --std=c++14 -O0 -fopenmp -o ./builds/c4_O0
#g++ run.cpp ./c4/matmul.cpp ../auxiliaries/auxiliaries.cpp ./tools.cpp -I ./c4/ -I ../auxiliaries --std=c++14 -O2 -fopenmp -o ./builds/c4_O2
