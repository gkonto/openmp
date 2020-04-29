#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <time.h>
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


long TestQuickSort::choosePivot(long *a, long lo, long hi) {
        return (lo + hi) / 2;
}

long TestQuickSort::partitionArray(long *a, long lo, long hi)
{
    long pivotIndex = choosePivot(a, lo, hi);
    long pivotValue = a[pivotIndex];

    std::swap(a[hi], a[pivotIndex]);
    long storeIndex = lo;

    for (long i = lo; i <= hi - 1; ++i) {
        if (a[i] < pivotValue) {
            std::swap(a[i], a[storeIndex]);
            ++storeIndex;
        }
    }
    std::swap(a[storeIndex], a[hi]);

    return storeIndex;
}

void TestQuickSort::seqQuickSort(long *a, long lo, long hi)
{
    if (lo < hi) {
        long p = partitionArray(a, lo, hi);
        seqQuickSort(a, lo, p - 1); // left branch
        seqQuickSort(a, p + 1, hi); // right branch
    }
}

void TestQuickSort::initialize(std::vector<long> &vec) 
{
    srand(time(nullptr));
    for (auto &a : vec) {
        a = rand() % 100000 + 1;
    }
}


void TestQuickSort::ompQuickSort(long *a, long lo, long hi) {
    if (lo < hi) { 
        long p = partitionArray(a, lo, hi);
        #pragma omp task default(none) shared(a) firstprivate(lo, p)
        {
            ompQuickSort(a, lo, p-1); // Left branch
        }

        #pragma omp task default(none), shared(a) firstprivate(hi, p)
        {
            ompQuickSort(a, p+1, hi); // Right branch
        }
    }
}

// The OpenMP quicksort implementation using the final and 
// mergeable clauses
// TODO the cutoff value can be set such that the OpenMP version
// using a single thread performs the same as or similar to the 
// sequential version.
void TestQuickSort::ompQuickSort2(long *a, long lo, long hi) {
    long cutoff_tasks = 50;
    if (lo < hi) {
        long p = partitionArray(a, lo, hi);
        #pragma omp task final ((p-lo) < cutoff_tasks) mergeable default(none) shared(a) firstprivate(lo, p)
        {
            // Left branch
            ompQuickSort2(a, lo, p - 1);
        }

        #pragma omp task final ((hi - p) < cutoff_tasks) mergeable default(none) shared(a) firstprivate(hi, p)
        {
            // Right branch
            ompQuickSort2(a, p + 1, hi);
        }
    }
}



TestQuickSort::TestQuickSort(long numOfElems)
    : Test("TestQuickSort")
{
    std::vector<long> initial(numOfElems);
    initialize(initial);
    std::vector<long> seq(initial);
    seqQuickSort(&seq[0], 0, seq.size() - 1);

    std::vector<long> par(initial);
    long *a = &par[0];
    size_t nelements = par.size();
    #pragma omp parallel default(none) shared(a, nelements)
    {
        #pragma omp single nowait
        {
            ompQuickSort(a, 0, nelements - 1);
        } // End of single section
    } // End of parallel section

    std::vector<long> par2(initial);
    a = &par2[0];
    nelements = par2.size();
    #pragma omp parallel default(none) shared(a, nelements)
    {
        #pragma omp single nowait
        {
            ompQuickSort(a, 0, nelements - 1);
        } // End of single section
    } // End of parallel section
}



