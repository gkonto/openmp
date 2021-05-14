#include <math.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <omp.h>
#include "prod_cons.hpp"
#include "../tools.hpp"

/*
 * NOTES:
 * Den einai producer consumer pragmatikos 
 * giati prota perimenei to single na teleiosei kai meta ksekinoyn ta tasks.
 */

Buffer *gl_buffer = 0;

int consume()
{
    int num = 0;
#pragma omp critical  
    {
        if (gl_buffer->len_ > 0) {
            num = gl_buffer->buf_[--gl_buffer->len_].x_;
            std::cout << "Consume: " << num << " Thread Id: " << omp_get_thread_num() << std::endl; 
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
        std::cout << "Produce: " << key << " Thread Id: " << omp_get_thread_num() << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


#if 0
int producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);
    int total = 0;
    int x = 0;

#pragma omp parallel 
    {
#pragma omp single
        {
            for (int i = 0; i < iterations; ++i) {
#pragma omp task depend(out : x)
                {
                    produce(i);
                    x = i;
                }
            }

            for (int i = 0; i < iterations; ++i) {
#pragma omp task depend(in : x)
                {
                    int temp = consume();
#pragma omp critical
                    {
                        std::cout << x << std::endl;
                        total += temp;
                    }
                }
            }
        }
    }
    return total;
}

#else

int producer_consumer(int iterations)
{
    gl_buffer = new Buffer(iterations);
    int total = 0;
    int x = 0;

#pragma omp parallel 
    {
#pragma omp single nowait
        {
            for (int i = 0; i < iterations; ++i) {
#pragma omp task depend(out : x)
                {
                    produce(i);
                    x = 1;
                }
            }

            for (int i = 0; i < iterations; ++i) {
#pragma omp task depend(in : x)
                {
                    int temp = consume();
#pragma omp critical
                    {
                        total += temp;
                    }
                }
            }
        }
    }
    return total;
}
#endif


