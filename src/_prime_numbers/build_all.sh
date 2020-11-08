#g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/prime.cpp -I ../auxiliaries -I sequential/  -Wall -Wextra -fopenmp -o ./builds/serial
#g++ run.cpp ../auxiliaries/auxiliaries.cpp sequential/prime.cpp -I ../auxiliaries -I sequential/  -Wall -Wextra -fopenmp -O2 -o ./builds/serial_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/prime.cpp -I ../auxiliaries -I c1/  -Wall -Wextra -fopenmp -o ./builds/c1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/prime.cpp -I ../auxiliaries -I c1/  -Wall -Wextra -fopenmp -O2 -o ./builds/c1_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/prime.cpp -I ../auxiliaries -I c1_1/  -Wall -Wextra -fopenmp -o ./builds/c1_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_1/prime.cpp -I ../auxiliaries -I c1_1/  -Wall -Wextra -fopenmp -O2 -o ./builds/c1_1_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/prime.cpp -I ../auxiliaries -I c1_2/  -Wall -Wextra -fopenmp -o ./builds/c1_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_2/prime.cpp -I ../auxiliaries -I c1_2/  -Wall -Wextra -fopenmp -O2 -o ./builds/c1_2_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/prime.cpp -I ../auxiliaries -I c1_3/  -Wall -Wextra -fopenmp -o ./builds/c1_3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c1_3/prime.cpp -I ../auxiliaries -I c1_3/  -Wall -Wextra -fopenmp -O2 -o ./builds/c1_3_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I ../auxiliaries -I c2/  -Wall -Wextra -fopenmp -o ./builds/c2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I ../auxiliaries -I c2/  -Wall -Wextra -fopenmp -O2 -o ./builds/c2_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I ../auxiliaries -I c2/  -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c2_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/prime.cpp -I ../auxiliaries -I c2/  -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c2_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/prime.cpp -I ../auxiliaries -I c2_1/  -Wall -Wextra -fopenmp -o ./builds/c2_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/prime.cpp -I ../auxiliaries -I c2_1/  -Wall -Wextra -fopenmp -O2 -o ./builds/c2_1_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/prime.cpp -I ../auxiliaries -I c2_1/  -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c2_1_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/prime.cpp -I ../auxiliaries -I c2_1/  -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c2_1_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I ../auxiliaries -I c2_2/  -Wall -Wextra -fopenmp -o ./builds/c2_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I ../auxiliaries -I c2_2/  -Wall -Wextra -fopenmp -O2 -o ./builds/c2_2_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I ../auxiliaries -I c2_2/  -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c2_2_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/prime.cpp -I ../auxiliaries -I c2_2/  -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c2_2_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I ../auxiliaries -I c3/  -Wall -Wextra -fopenmp -o ./builds/c3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I ../auxiliaries -I c3/  -Wall -Wextra -fopenmp -O2 -o ./builds/c3_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I ../auxiliaries -I c3/  -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c3_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/prime.cpp -I ../auxiliaries -I c3/  -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c3_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I ../auxiliaries -I c3_1/  -Wall -Wextra -fopenmp -o ./builds/c3_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I ../auxiliaries -I c3_1/  -Wall -Wextra -fopenmp -O2 -o ./builds/c3_1_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I ../auxiliaries -I c3_1/  -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c3_1_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c3_1/prime.cpp -I ../auxiliaries -I c3_1/  -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c3_1_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/prime.cpp -I ../auxiliaries -I c4/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4/prime.cpp -I ../auxiliaries -I c4/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/prime.cpp -I ../auxiliaries -I c4_1/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/prime.cpp -I ../auxiliaries -I c4_1/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_1_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_2/prime.cpp -I ../auxiliaries -I c4_2/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_2/prime.cpp -I ../auxiliaries -I c4_2/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_2_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_2/prime.cpp -I ../auxiliaries -I c4_2/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c4_2_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_2/prime.cpp -I ../auxiliaries -I c4_2/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c4_2_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/prime.cpp -I ../auxiliaries -I c4_3/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/prime.cpp -I ../auxiliaries -I c4_3/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_3_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_4/prime.cpp -I ../auxiliaries -I c4_4/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_4
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_4/prime.cpp -I ../auxiliaries -I c4_4/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_4_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_5/prime.cpp -I ../auxiliaries -I c4_5/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_5
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_5/prime.cpp -I ../auxiliaries -I c4_5/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_5_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_6/prime.cpp -I ../auxiliaries -I c4_6/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_6
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_6/prime.cpp -I ../auxiliaries -I c4_6/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_6_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_7/prime.cpp -I ../auxiliaries -I c4_7/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_7
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_7/prime.cpp -I ../auxiliaries -I c4_7/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_7_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_7/prime.cpp -I ../auxiliaries -I c4_7/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c4_7_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_7/prime.cpp -I ../auxiliaries -I c4_7/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c4_7_O2_simd

#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_8/prime.cpp -I ../auxiliaries -I c4_8/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_8
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_8/prime.cpp -I ../auxiliaries -I c4_8/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_8_O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_8/prime.cpp -I ../auxiliaries -I c4_8/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -fopenmp-simd -o ./builds/c4_8_simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_8/prime.cpp -I ../auxiliaries -I c4_8/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -fopenmp-simd -O2 -o ./builds/c4_8_O2_simd

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_9/prime.cpp -I ../auxiliaries -I c4_9/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_9
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_9/prime.cpp -I ../auxiliaries -I c4_9/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_9_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_10/prime.cpp -I ../auxiliaries -I c4_10/ -fno-stack-protector -foffload=nvptx-none -Wall -Wextra -fopenmp -o ./builds/c4_10
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_10/prime.cpp -I ../auxiliaries -I c4_10/ -fno-stack-protector -foffload=nvptx-none="-O2" -Wall -Wextra -fopenmp -O2 -o ./builds/c4_10_O2

