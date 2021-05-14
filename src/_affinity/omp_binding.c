
#include <omp.h>
#include <sched.h>
#include <iostream>

int main( int argc, char**argv )
{
#pragma omp parallel
    {
#pragma omp critical
        std::cout << "Running from thread " << omp_get_thread_num() + 1 <<
            " of " << omp_get_num_threads() << " running on cpu " << sched_getcpu() << std::endl;
    }
    return 0;
}

