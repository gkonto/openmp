#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <omp.h>
#include "prod_cons.hpp"

/*
 * NOTES:
 * Den einai producer consumer pragmatikos 
 * giati prota perimenei to single na teleiosei kai meta ksekinoyn ta tasks.
 */

void cProd(int *A, int *B, int *c)
{
    c[0] = A[1] * B[2] - A[2] * B[1];
    c[1] = -(A[0] * B[2] - A[2] * B[0]);
    c[2] = A[0] * B[1] - A[1] * B[0];
}


void fill_random(int *arr)
{
    arr[0] = rand() % 10 + 1;
    arr[1] = rand() % 10 + 1;
    //#arr[2] = rand() % 10 + 1;
}


struct Dummy {
    Dummy() = default;
    explicit Dummy(int x) : x_(x) {}
    int x_ = 0; // 1 bytes
    char padding[60] = {0};
};

struct Buffer
{
    explicit Buffer(int size) 
        : len_(-1), buf_(new Dummy[size]) {}

    ~Buffer() {
        delete []buf_;
    }

    int len_ = -1;
    Dummy *buf_ = 0;
};

Buffer *gl_buffer = 0;

int consume()
{
    int num = 0;
#pragma omp critical  
    {
        if (gl_buffer->len_ >= 0) {
            num = gl_buffer->buf_[--gl_buffer->len_].x_;
            std::cout << "Consuming: " << num << " Thread: " << omp_get_thread_num() << std::endl; 
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return num;
}


void produce(int key)
{
#pragma omp critical
    {
        gl_buffer->buf_[++gl_buffer->len_].x_ = key;
        std::cout << "Producing: " << key << " Thread Id: " << omp_get_thread_num() << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}


void producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);
    long long int total = 0;
    int finished_production = 0;

#pragma omp parallel shared(finished_production)
    {
#pragma omp single 
        {
            for (int i = 0; i < iterations; ++i) {
                produce(i);
            }
            finished_production = 1;
        }

        int keep_on = 1;
#pragma omp task firstprivate(keep_on)
        while (keep_on) {
            long long int temp = consume();
            long long int sum = 0;
            sum += temp;

            if (finished_production && gl_buffer->len_ < 0) {
                keep_on = 0; 
#pragma omp critical
                {
                    std::cout << "Finished thread: " << omp_get_thread_num() << std::endl;
                    total += sum;
                } 
            }
        }
    }
}


