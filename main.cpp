#include "tests.hpp"

int main(void) 
{
    TestOpenMP t1;
    TestUpdateSharedVariable t2;
    TestLoopCollapse t3(10000, 10000);
    return 0;
}
