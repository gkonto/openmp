#include <omp.h>
#include <stdio.h>
#include <sched.h>

int main( int argc, char**argv )
{
    for (int i=1; i<100; i++){
	#pragma omp parallel
	    {
	        printf( "Running from thread %d of %d on cpu %2d!\n", 
	            omp_get_thread_num()+1, 
	            omp_get_num_threads(),
	            sched_getcpu());
	    }
    }	    
    return 0;
}

