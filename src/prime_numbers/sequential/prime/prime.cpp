#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prime.hpp"

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
  Parameters:
    Input, int N, the maximum number to check.
    Output, int PRIME_NUMBER, the number of prime numbers up to N.
*/
int prime_number(int n)
{
  int prime;
  int total = 0;

  for (int i = 2; i <= n; i++) {
    prime = 1;
    for (int j = 2; j < i; j++) {
      if ((i % j) == 0) {
        prime = 0;
        break;
      }
    }
    total = total + prime;
  }
  return total;
}
/******************************************************************************/

