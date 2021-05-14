#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include "prod_cons.hpp"
#include "../tools.hpp"
#include <omp.h>

Buffer *gl_buffer = 0;

int consume()
{
    int num = 0;
#pragma omp critical
    {
        num = gl_buffer->buf_[--gl_buffer->len_].x_;
        std::cout << "Consume: " << num << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    return num;
}

void produce(int key)
{
#pragma omp critical
    {
        gl_buffer->buf_[gl_buffer->len_++].x_ = key;
        std::cout << "Produce: " << key << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);
    long long int total = 0;

#pragma omp parallel for reduction(+: total)
    for (int i = 0; i < iterations; ++i) {
        produce(i);
        total += consume();
    }

    return total;
}


