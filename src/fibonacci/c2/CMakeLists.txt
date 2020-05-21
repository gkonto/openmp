 cmake_minimum_required(VERSION 2.8.7)

 PROJECT(c2)
 SET(CMAKE_CXX_STANDARD 14)

 ADD_DEFINITIONS("-fopenmp -L/usr/local/bin -g -Wall -Wextra -O3 -Wunreachable-code")

 INCLUDE_DIRECTORIES(fib)
 LINK_DIRECTORIES(fib)
 ADD_SUBDIRECTORY(fib)

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(PROJECT run_fib)

  INCLUDE_DIRECTORIES(${FIB_DIR})
  INCLUDE_DIRECTORIES(${AUX_DIR})

 SET(SOURCES
     run.cpp
      ${AUX_DIR}/auxiliaries.hpp
      ${AUX_DIR}/auxiliaries.cpp
     )

 ADD_EXECUTABLE(run_fib ${HEADERS} ${SOURCES})

 TARGET_LINK_LIBRARIES(run_fib fib)

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()
