  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")
  ADD_SUBDIRECTORY(matmul)

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(MAT_MUL ${ROOT_DIR}/matrix_multiplication)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(PROJECT mat_mul)

  INCLUDE_DIRECTORIES(${AUX_DIR})
  INCLUDE_DIRECTORIES(${MAT_MUL})

  SET(SOURCES
      run.cpp
      ${AUX_DIR}/auxiliaries.cpp
      ${AUX_DIR}/auxiliaries.hpp
      ${MAT_MUL}/tools.hpp
      ${MAT_MUL}/tools.cpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(${PROJECT} matmul)

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()



