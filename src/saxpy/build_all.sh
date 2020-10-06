# Serial 
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial_/saxpy.cpp -I serial_/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/serial
# Serial --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp serial_/saxpy.cpp -I serial_/ -I ../auxiliaries/ -fopenmp -Wall -std=c++14 -O2 -Wextra -o ./builds/serial_O2

# c1 
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/saxpy.cpp -I c1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c1
# c1 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c1/saxpy.cpp -I c1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c1_O2

# c1_1
g++ run_padding_struct.cpp ../auxiliaries/auxiliaries.cpp c1_1/saxpy.cpp -I c1_1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c1_1
# c1_1 --std=c++14 -O2
g++ run_padding_struct.cpp ../auxiliaries/auxiliaries.cpp c1_1/saxpy.cpp -I c1_1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c1_1_O2

# c2 
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c2
# c2  simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -o ./builds/c2_simd
# c2 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_O2
# c2 --std=c++14 -O2 -fopenmp-simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2/saxpy.cpp -I c2/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_O2_simd

# c2_1
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c2_1
# c2_1  simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -o ./builds/c2_1_simd
# c2_1 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_1_O2
# c2_1 --std=c++14 -O2 -fopenmp-simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_1/saxpy.cpp -I c2_1/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_1_O2_simd

# c2_2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c2_2
# c2_2  simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -o ./builds/c2_2_simd
# c2_2 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_2_O2
# c2_2 --std=c++14 -O2 -fopenmp-simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c2_2/saxpy.cpp -I c2_2/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/c2_2_O2_simd

# c3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -o ./builds/c3
# c3  simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -o ./builds/c3_simd
# c3 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -o ./builds/c3_O2
# c3 --std=c++14 -O2 -fopenmp-simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c3/saxpy.cpp -I c3/ -I ../auxiliaries/ -fopenmp -fopenmp-simd -Wall -Wextra -std=c++14 -O2 -o ./builds/c3_O2_simd

# c4_1
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/saxpy.cpp -I c4_1/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1
# c4_1 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1/saxpy.cpp -I c4_1/ -I ../auxiliaries/ -fopenmp -Wall -Wextra -std=c++14 -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -o ./builds/c4_1_O2

# c4_1_0
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_0
# c4_1_0 simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_0_simd
# c4_1_0 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_1_0_O2
# c4_1_0 simd -std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_0/saxpy.cpp -I c4_1_0/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_0_simd_O2

# c4_1_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_1/saxpy.cpp -I c4_1_1/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_1
# c4_1_1 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_1/saxpy.cpp -I c4_1_1/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_1_O2

# c4_1_2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_2/saxpy.cpp -I c4_1_2/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_2
# c4_1_2 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_2/saxpy.cpp -I c4_1_2/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_2_O2

# c4_1_3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_3
# c4_1_3 simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_3_simd
# c4_1_3 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_1_3_O2
# c4_1_3 simd -std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_3/saxpy.cpp -I c4_1_3/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_3_simd_O2

# c4_1_4
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_4/saxpy.cpp -I c4_1_4/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_4
# c4_1_4 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_4/saxpy.cpp -I c4_1_4/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_4_O2

# c4_1_5
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_5/saxpy.cpp -I c4_1_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_5
# c4_1_5 simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_5/saxpy.cpp -I c4_1_5/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_5_simd
# c4_1_5 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_5/saxpy.cpp -I c4_1_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_1_5_O2
# c4_1_5 simd -std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_5/saxpy.cpp -I c4_1_5/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_5_simd_O2

# c4_1_6
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_6/saxpy.cpp -I c4_1_6/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_6
# c4_1_6 simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_6/saxpy.cpp -I c4_1_6/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_1_6_simd
# c4_1_6 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_6/saxpy.cpp -I c4_1_6/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_1_6_O2
# c4_1_6 simd -std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_1_6/saxpy.cpp -I c4_1_6/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_1_6_simd_O2

# c4_3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/saxpy.cpp -I c4_3/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3
# c4_3 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3/saxpy.cpp -I c4_3/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_O2

# c4_3_0
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_0/saxpy.cpp -I c4_3_0/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_0
# c4_3_0 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_0/saxpy.cpp -I c4_3_0/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_0_O2

# c4_3_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_1/saxpy.cpp -I c4_3_1/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_1
# c4_3_1 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_1/saxpy.cpp -I c4_3_1/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_1_O2

# c4_3_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_2/saxpy.cpp -I c4_3_2/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_2
# c4_3_2 simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_2/saxpy.cpp -I c4_3_2/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_2_simd
# c4_3_2 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_2/saxpy.cpp -I c4_3_2/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_3_2_O2
# c4_3_2 simd -std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_2/saxpy.cpp -I c4_3_2/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_2_simd_O2

# c4_3_3
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_3/saxpy.cpp -I c4_3_3/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_3
# c4_3_3 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_3/saxpy.cpp -I c4_3_3/ -I ../auxiliaries/ -fno-stack-protector --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_3_O2


# c4_3_4
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_4
# c4_3_4 simd
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_4_simd
# c4_3_4 --std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_3_4_O2
# c4_3_4 simd -std=c++14 -O2
g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_4/saxpy.cpp -I c4_3_4/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_4_simd_O2


# c4_3_5
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_5
# c4_3_5 simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_5_simd
# c4_3_5 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_3_5_O2
# c4_3_5 simd -std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_5/saxpy.cpp -I c4_3_5/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_5_simd_O2


# c4_3_6
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_6
# c4_3_6 simd
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_3_6_simd
# c4_3_6 --std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_3_6_O2
# c4_3_6 simd -std=c++14 -O2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp c4_3_6/saxpy.cpp -I c4_3_6/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_3_6_simd_O2

# c4_4
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_4
# c4_4 simd
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd  -foffload=nvptx-none -fopenmp -Wall -Wextra -o ./builds/c4_4_simd
# c4_4 --std=c++14 -O2
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -fno-stack-protector  -foffload=nvptx-none="-O2" --std=c++14 -O2 -fopenmp -Wall -Wextra -o ./builds/c4_4_O2
# c4_4 simd -std=c++14 -O2
g++ run_device_alloc.cpp ../auxiliaries/auxiliaries.cpp c4_4/saxpy.cpp -I c4_4/ -I ../auxiliaries/ -fno-stack-protector -fopenmp-simd --std=c++14 -O2 -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -o ./builds/c4_4_simd_O2

