 cmake_minimum_required(VERSION 2.8.7)
 PROJECT(matmul)
 add_definitions("-g -Wall -Wextra -O0 -Wunreachable-code")

 set(CMAKE_CXX_STANDARD 14)

 set(HEADERS
     addarr.hpp
   )

 set(SOURCES
     addarr.cpp
     )

 ADD_LIBRARY(addarr ${HEADERS} ${SOURCES})

