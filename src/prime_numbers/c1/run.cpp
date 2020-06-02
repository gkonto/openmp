# include <stdlib.h>
# include <stdio.h>
# include <omp.h>
#include <iostream>
#include "auxiliaries.hpp"

int prime_number ( int n );

/*
  Purpose:

   PRIME_NUMBER_SWEEP does repeated calls to PRIME_NUMBER.
    Input, int N_LO, the first value of N.

    Input, int N_HI, the last value of N.

    Input, int N_FACTOR, the factor by which to increase N after
    each iteration.
*/
void prime_number_sweep ( int n_hi)
{
  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Call PRIME_NUMBER to count the primes from 1 to N.\n" );
  printf ( "\n" );
  printf ( "         N        Pi \n" );
  printf ( "\n" );

    int primes = prime_number ( n_hi );


    printf ( "  %8d  %8d \n", n_hi, primes);
 
  return;
}

/******************************************************************************/


/******************************************************************************/
namespace {
    struct Opts {
        int num_threads_;
        int max_;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {

  if (argc != 3) {
    std::cout << "Specify max boundary and thread number" << std::endl;
    exit(1);
  }
  read_value<int>(argv[1], o.max_);
  read_value<int>(argv[2], o.num_threads_);
}

/*
  Purpose:
    MAIN is the main program for PRIME_OPENMP.
*/
int main ( int argc, char *argv[] )
{
    Opts o;
    parseArgs(argc, argv, o);

    omp_set_num_threads(o.num_threads_);

  printf ( "\n" );
  printf ( "PRIME_OPENMP\n" );
  printf ( "  C/OpenMP version\n" );

  printf ( "\n" );
  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

  double start = omp_get_wtime();
  prime_number_sweep ( o.max_);
  std::cout << "Execution Time: " << omp_get_wtime() - start << " seconds" << std::endl;
  

  return 0;
}
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/*
  Purpose:

    PRIME_NUMBER returns the number of primes between 1 and N.

  Discussion:

    A naive algorithm is used.

    Mathematica can return the number of primes less than or equal to N
    by the command PrimePi[N].

                N  PRIME_NUMBER

                1           0
               10           4
              100          25
            1,000         168
           10,000       1,229
          100,000       9,592
        1,000,000      78,498
       10,000,000     664,579
      100,000,000   5,761,455
    1,000,000,000  50,847,534

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the maximum number to check.

    Output, int PRIME_NUMBER, the number of prime numbers up to N.
*/
int prime_number ( int n )
{
  int i;
  int j;
  int prime;
  int total = 0;

# pragma omp parallel \
  shared ( n ) \
  private ( i, j, prime )
  

# pragma omp for reduction ( + : total )
  for ( i = 2; i <= n; i++ )
  {
    prime = 1;

    for ( j = 2; j < i; j++ )
    {
      if ( i % j == 0 )
      {
        prime = 0;
        break;
      }
    }
    total = total + prime;
  }

  return total;
}

