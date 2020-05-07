  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")
  ADD_SUBDIRECTORY(integrate)

  SET(SOURCES
      run.cpp
      )

  ADD_EXECUTABLE(pi ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(pi integrate)
  #TARGET_LINK_LIBRARIES(run_fib aparser)

 find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(pi PUBLIC OpenMP::OpenMP_CXX)
endif()


