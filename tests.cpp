#include <memory>
#include <iostream>
#include "threads.hpp"
#include "tests.hpp"
#include "linked_list.hpp"
#include <omp.h>

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


// Figure 3.9
long TestLinkedList::do_work(long input) {
    long return_value = 0;
    long TID = omp_get_thread_num();
    const int MAX_ERRORS = 10;

    #pragma omp critical
    {
        function_call_count++;
        printf("TID = %-6ld Input: %-6ld function_call_count: %d\n", TID, input, function_call_count);

        if (function_call_count <= MAX_ERRORS) {
            return_value =  -(TID + 1);
        } else {
            return_value = 0;
        }
    } // End of critical region
    return (return_value);
}


void TestLinkedList::initialize_list() {
    // Figure 3.7
    // A for-loop with this length is used to construct the list.
    linked_list *ptr = nullptr;
    linked_list *previous = nullptr;

    for (long i = 0; i < ntasks_; i++) {
        ptr = new linked_list;
        if (!ptr) {
            perror("ptr");
            exit(-1);
        }

        i == 0 ? head_ = ptr : previous->next = ptr;

        ptr->value_ = i + 1;
        ptr->next = nullptr;
        previous = ptr;
    }
}


// Figure 3.8
// The sequential implementation of the linked list program
void TestLinkedList::sequentialImpl() {
    function_call_count = 0;
    int no_of_tasks_failed = 0;

    linked_list *current = head_;
    while (current) {
        long return_value = do_work(current->value_);
        if (return_value < 0) {
            no_of_tasks_failed++;
        }
        current = current->next;
    } // End of while loop
}


void TestLinkedList::parallelImpl() {
    function_call_count = 0;
    int no_of_tasks_failed = 0;
    linked_list *current = head_;

    #pragma omp parallel firstprivate(current) shared(no_of_tasks_failed)
    {
        #pragma omp single nowait
        {
            printf("Thread %d executes the single region\n", omp_get_thread_num());
            while (current) {
                #pragma omp task firstprivate(current) shared(no_of_tasks_failed)
                {
                    long return_value = do_work(current->value_);
                    if (return_value < 0) {
                        #pragma omp atomic update
                        ++no_of_tasks_failed;
                    }
                } // End of task
                current = current->next;
            } // End of while loop
        } // End of single region
    } // End of parallel region
}


TestLinkedList::TestLinkedList()
    : Test("TestLinkedList")
{
    initialize_list();
    sequentialImpl();
    parallelImpl();
}
