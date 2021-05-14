#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include "../tools.hpp"
#include "prod_cons.hpp"


Buffer *gl_buffer = 0;

int consume()
{
    int num = gl_buffer->buf_[--gl_buffer->len_].x_;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    return num;
}

void produce(int key)
{
    gl_buffer->buf_[gl_buffer->len_++].x_ = key;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);

    int total = 0;

    for (int i = 0; i < iterations; ++i) {
        produce(i);
        total += consume();
    }

    return total;
}


