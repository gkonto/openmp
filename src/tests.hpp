#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>
#include <vector>

//Forward declarations
struct linked_list;

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


// Figure 3.6
// Implementation of a linked list program
struct TestLinkedList : public Test {
    TestLinkedList();
    long do_work(long input_value);
    void initialize_list();
    // Figure 3.8
    void sequentialImpl();
    // Figure 3.10
    void parallelImpl();

    linked_list *head_ = nullptr;
    int function_call_count = 0;
    int ntasks_ = 15;
};


struct TestQuickSort : public Test {
    TestQuickSort(long numOfElems);

    void initialize(std::vector<long> &initial);
    // Figure 3.15
    void seqQuickSort(long *a, long lo, long hi);
    // Figure 3.17
    void ompQuickSort(long *a, long lo, long hi);
    //Figure 3.19
    void ompQuickSort2(long *a, long lo, long hi);

    long choosePivot(long *a, long lo, long hi);
    long partitionArray(long *a, long lo, long hi);
};

#endif
