#g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/serial
#g++ run.cpp serial/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I serial -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/serial_O2

#g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c1
#g++ run.cpp c1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c1_O2
#
#g++ run.cpp c1_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1_1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c1_1
#g++ run.cpp c1_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c1_1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c1_1_O2
#
#g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O0 -Wall -Wextra -o builds/c2
##g++ run.cpp c2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2 -fopenmp --std=c++11 -O2 -Wall -Wextra -o builds/c2_O2
#
#g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c2_1
#g++ run.cpp c2_1/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_1 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c2_1_O2

#g++ run.cpp c2_2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_2 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c2_2
#g++ run.cpp c2_2/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c2_2 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c2_2_O2

#g++ run.cpp c3/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c3 -fopenmp --std=c++11 -Wall -Wextra -O0 -o builds/c3
#g++ run.cpp c3/qsort.cpp ../auxiliaries/auxiliaries.cpp -I ../auxiliaries -I c3 -fopenmp --std=c++11 -Wall -Wextra -O2 -o builds/c3_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3/ -o ./builds/c3_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_1/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_1/ -o ./builds/c3_1_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_2/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_2/ -o ./builds/c3_2_O2

#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3
#g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_3/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_3/ -o ./builds/c3_3_O2

g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/qsort.cpp -O0 -fno-stack-protector -foffload=nvptx-none -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4
g++ run.cpp ../auxiliaries/auxiliaries.cpp ./c3_4/qsort.cpp -O2 -fno-stack-protector -foffload=nvptx-none="-O2" -fopenmp -Wall -Wextra -I ../auxiliaries -I ./c3_4/ -o ./builds/c3_4_O2
