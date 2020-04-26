 cmake_minimum_required(VERSION 2.8.7)
 PROJECT(thesis)
 add_definitions("-fopenmp -L/usr/local/bin -g -Wall -Wextra -O0 -Wunreachable-code")

 set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
 set(CMAKE_CXX_STANDARD 14)

 set(HEADERS
     threads.hpp
     tests.hpp
   )

 set(SOURCES
     main.cpp
     tests.cpp
     )

 ADD_EXECUTABLE(thesis_api ${HEADERS} ${SOURCES})

 find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(thesis_api PUBLIC OpenMP::OpenMP_CXX)
endif()


