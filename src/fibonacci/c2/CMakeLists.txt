 cmake_minimum_required(VERSION 2.8.7)

 PROJECT(c2)
 SET(CMAKE_CXX_STANDARD 14)

 ADD_DEFINITIONS("-fopenmp -L/usr/local/bin -g -Wall -Wextra -O3 -Wunreachable-code")

 INCLUDE_DIRECTORIES(fib)
 LINK_DIRECTORIES(fib)
 ADD_SUBDIRECTORY(fib)

 SET(SOURCES
     run.cpp
     )

 ADD_EXECUTABLE(run_fib ${HEADERS} ${SOURCES})

 TARGET_LINK_LIBRARIES(run_fib fib)

