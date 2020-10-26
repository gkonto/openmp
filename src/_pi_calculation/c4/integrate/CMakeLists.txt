 cmake_minimum_required(VERSION 2.8.7)
 PROJECT(matmul)
 add_definitions("-g -Wall -Wextra -O0 -Wunreachable-code")

 set(CMAKE_CXX_STANDARD 14)

 set(HEADERS
     integ.hpp
   )

 set(SOURCES
     integ.cpp
     )

 ADD_LIBRARY(integrate ${HEADERS} ${SOURCES})

 find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(integrate PUBLIC OpenMP::OpenMP_CXX)
endif()


