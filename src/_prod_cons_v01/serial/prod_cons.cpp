#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include "prod_cons.hpp"

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
    explicit Buffer(size_t size) 
        : len_(0), buf_(new Dummy[size]) {}

    ~Buffer() {
        delete []buf_;
    }

    size_t len_ = 0;
    Dummy *buf_ = 0;
};

Buffer *gl_buffer = 0;

int consume()
{
    int num = gl_buffer->buf_[--gl_buffer->len_].x_;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << num << std::endl;
    return num;
}

void produce(int key)
{
    gl_buffer->buf_[gl_buffer->len_++].x_ = key;
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

void producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);

    long long int total = 0;

    for (int i = 0; i < iterations; ++i) {
        produce(i);
        total += consume();
    }

    std::cout << "Total: " << total << std::endl;
}


