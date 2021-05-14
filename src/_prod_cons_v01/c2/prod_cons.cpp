#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <omp.h>
#include "prod_cons.hpp"
#include "../tools.hpp"

Buffer *gl_buffer = 0;

int consume()
{
    int num = 0;
#pragma omp critical  
    {
        if (gl_buffer->len_ > 0) {
            num = gl_buffer->buf_[--gl_buffer->len_].x_;
            std::cout << "Consume: " << num << std::endl;
        }
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
    int total = 0;
    int finished_production = 0;
    int abort = 0;

#pragma omp parallel shared(finished_production) firstprivate(abort)
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < iterations; ++i) {
                produce(i);
            }
            finished_production = 1;
        } else {
            while (!abort) {
                int temp = consume();
#pragma omp critical
                {
                    total += temp;
                    if (finished_production && gl_buffer->len_ == 0) {
                        abort = 1;
                    }
                }
            }
        }
    }

    return total;
}


