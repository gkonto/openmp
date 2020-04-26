#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>

class Test {
public:
    Test(const std::string &name);
protected:
    std::string name_;
};

// Figure 1.4
// Simple test to check whether compiler identifies successfully
// the OpenMP library
struct TestOpenMP : public Test{
    TestOpenMP();
};

// Figure 1.6
// Example of the update of a shared variable.
struct TestUpdateSharedVariable : public Test {
    TestUpdateSharedVariable();
};


// Figure 2.6   
// Example of the loop collapse clause
struct TestLoopCollapse : public Test {
    TestLoopCollapse(int dim1, int dim2);
};


#endif
