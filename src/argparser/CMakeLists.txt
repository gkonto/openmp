 cmake_minimum_required(VERSION 2.8.7)
 PROJECT(argparser)
 add_definitions("-g -Wall -Wextra -O3 -Wunreachable-code")

 set(CMAKE_CXX_STANDARD 14)

 set(HEADERS
     argparser.hpp
   )

 set(SOURCES
     argparser.cpp
     )

 ADD_LIBRARY(argparser ${HEADERS} ${SOURCES})

