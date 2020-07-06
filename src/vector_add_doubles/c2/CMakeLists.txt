  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS(" -fopenmp-simd -g -Wall -Wextra -O0 -Wunreachable-code")
  ADD_SUBDIRECTORY(addarr)

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(VEC_ADD ${ROOT_DIR}/vector_add_doubles)
  SET(PROJECT add_arrays)

  INCLUDE_DIRECTORIES(${AUX_DIR})
  INCLUDE_DIRECTORIES(${VEC_ADD})

  SET(SOURCES
      run.cpp
      ${AUX_DIR}/auxiliaries.cpp
      ${AUX_DIR}/auxiliaries.hpp
      ${VEC_ADD}/tools.hpp
      ${VEC_ADD}/tools.cpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(${PROJECT} addarr)

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()



