#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./serial/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./serial/ -o ./builds/serial_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1/ -o ./builds/c1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1/ -o ./builds/c1_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_1/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_1/ -o ./builds/c1_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_1/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_1/ -o ./builds/c1_1_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_2/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_2/ -o ./builds/c1_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c1_2/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c1_2/ -o ./builds/c1_2_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2/ -o ./builds/c2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2/ -o ./builds/c2_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2/dprod.cpp -O0 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2/ -o ./builds/c2_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2/dprod.cpp -O2 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2/ -o ./builds/c2_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_1/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2_1/ -o ./builds/c2_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_1/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2_1/ -o ./builds/c2_1_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_1/dprod.cpp -O0 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2_1/ -o ./builds/c2_1_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_1/dprod.cpp -O2 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2_1/ -o ./builds/c2_1_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_2/dprod.cpp -O0 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2_2/ -o ./builds/c2_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_2/dprod.cpp -O2 -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c2_2/ -o ./builds/c2_2_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_2/dprod.cpp -O0 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2_2/ -o ./builds/c2_2_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c2_2/dprod.cpp -O2 -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c2_2/ -o ./builds/c2_2_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_5/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_5/ -o ./builds/c3_5
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_5/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_5/ -o ./builds/c3_5_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_6/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_6/ -o ./builds/c3_6
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_6/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_6/ -o ./builds/c3_6_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7/ -o ./builds/c3_7
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7/ -o ./builds/c3_7_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7_1/ -o ./builds/c3_7_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7_1/ -o ./builds/c3_7_1_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7_2/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7_2/ -o ./builds/c3_7_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_7_2/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_7_2/ -o ./builds/c3_7_2_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_8/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_8/ -o ./builds/c3_8
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_8/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_8/ -o ./builds/c3_8_O2
#
#++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_8_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_8_1/ -o ./builds/c3_8_1
#++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_8_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_8_1/ -o ./builds/c3_8_1_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9/ -o ./builds/c3_9
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9/ -o ./builds/c3_9_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9_1/ -o ./builds/c3_9_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9_1/ -o ./builds/c3_9_1_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9_2/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9_2/ -o ./builds/c3_9_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_9_2/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_9_2/ -o ./builds/c3_9_2_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_10/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_10/ -o ./builds/c3_10
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_10/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_10/ -o ./builds/c3_10_O2
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_11/ -o ./builds/c3_11
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_11/ -o ./builds/c3_11_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_11/ -o ./builds/c3_11_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_11/ -o ./builds/c3_11_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_11_1/ -o ./builds/c3_11_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_11_1/ -o ./builds/c3_11_1_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11_1/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_11_1/ -o ./builds/c3_11_1_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_11_1/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_11_1/ -o ./builds/c3_11_1_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_12/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_12/ -o ./builds/c3_12
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_12/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_12/ -o ./builds/c3_12_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_12/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_12/ -o ./builds/c3_12_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_12/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_12/ -o ./builds/c3_12_O2_simd
#
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_14/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_14/ -o ./builds/c3_14
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_14/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_14/ -o ./builds/c3_14_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_14/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_14/ -o ./builds/c3_14_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_14/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_14/ -o ./builds/c3_14_O2_simd
#

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_15/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_15/ -o ./builds/c3_15
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_15/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_15/ -o ./builds/c3_15_O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_15/dprod.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_15/ -o ./builds/c3_15_simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_15/dprod.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -fopenmp-simd -Wall -Wextra -I ../auxiliaries -I ./c3_15/ -o ./builds/c3_15_O2_simd
