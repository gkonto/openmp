#include "tests.hpp"

int main(void) 
{
    TestOpenMP t1;
    TestUpdateSharedVariable t2;
    TestLoopCollapse t3(500, 500);
    return 0;
}
