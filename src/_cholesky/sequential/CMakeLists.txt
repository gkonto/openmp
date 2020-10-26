  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(CHOL ${ROOT_DIR}/cholesky)
  SET(PROJECT cholesky)

  INCLUDE_DIRECTORIES(${AUX_DIR})
  INCLUDE_DIRECTORIES(${CHOL})

  SET(SOURCES
      run.cpp
      ${AUX_DIR}/auxiliaries.cpp
      ${AUX_DIR}/auxiliaries.hpp
      ${CHOL}/tools.hpp
      ${CHOL}/tools.cpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()


