#include <memory>
#include <iostream>
#include "threads.hpp"
#include "tests.hpp"

Test::Test(const std::string &name) 
    : name_(name)
{
    std::cout << "[+] " << name_ << std::endl;
}

TestOpenMP::TestOpenMP()
    : Test("TestOpenMP")
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
        x += y; // y was pre-initialized to a value of 20
        y = 30; // (first) private variable may be modified
    } // End of parallel region
}


TestUpdateSharedVariable::TestUpdateSharedVariable() 
    : Test("TestUpdateSharedVariable")
{
    int sum = 0;
    #pragma omp parallel shared(sum)
    {
        // Contains the per-thread partial sum;
        int contribution = 5;

        // To avoid multiple threads updating shared variable sum
        // at the same time, a critical region is used.
        // (Avoid data race)
        #pragma omp critical
        {
            sum += contribution;
        } // End of critical region
    } // End of parallel region
}



TestLoopCollapse::TestLoopCollapse(int n, int m) 
    : Test("TestLoopCollapse")
{
    std::unique_ptr<int[]> a = std::make_unique<int[]>(m*n);
    
    #pragma omp parallel for default(none) shared(a, m, n) collapse(2)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i*n+j] = i + j + 1;
        }
    }
}
