#include "threads.hpp"
#include "tests.hpp"

TestOpenMP::TestOpenMP()
{
    int x = 5;
    int y = 20;
    #pragma omp parallel private(x) firstprivate(y)
    {
        int k = 0;
        for (long long i = 0; i < 1000000000; i++) {
            k++;
        }
        x = 10; // x is undefined on entry, but now set to 10
        int z = x + y; // y was pre-initializedto a value of 20
        y = 30; // (first) private variable may be modified
    } // End of parallel region
}
