 cmake_minimum_required(VERSION 2.8.7)
 PROJECT(fib)
 add_definitions("-fopenmp -L/usr/local/bin -g -Wall -Wextra -O3 -Wunreachable-code")

 set(CMAKE_CXX_STANDARD 14)

 set(HEADERS
     fib.hpp
   )

 set(SOURCES
     fib.cpp
     )

 ADD_LIBRARY(fib ${HEADERS} ${SOURCES})

 find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(fib PUBLIC OpenMP::OpenMP_CXX)
endif()


