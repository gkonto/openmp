  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(c1)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-fopenmp -L/usr/local/bin -g -Wall -Wextra -O3 -Wunreachable-code")
  ADD_SUBDIRECTORY(fib)

  ADD_LIBRARY(aparser ../../argparser/argparser.hpp ../../argparser/argparser.cpp)

  SET(SOURCES
      run.cpp
      )

  ADD_EXECUTABLE(run_fib ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(run_fib fib)
  TARGET_LINK_LIBRARIES(run_fib aparser)



