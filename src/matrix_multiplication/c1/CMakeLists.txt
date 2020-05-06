  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")
  ADD_SUBDIRECTORY(matmul)

  SET(SOURCES
      run.cpp
      )

  ADD_EXECUTABLE(mat_mul ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(mat_mul matmul)
  #TARGET_LINK_LIBRARIES(run_fib aparser)



