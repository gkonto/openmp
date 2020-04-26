#ifndef TESTS_HPP
#define TESTS_HPP

// Figure 1.4
// Simple test to check whether compiler identifies successfully
// the OpenMP library
struct TestOpenMP {
    TestOpenMP();
};

// Figure 1.6
// Example of the update of a shared variable.
struct TestUpdateSharedVariable {
    TestUpdateSharedVariable();
};


// Figure 2.6   
// Example of the loop collapse clause
struct TestLoopCollapse {
    TestLoopCollapse(int dim1, int dim2);
};


#endif
