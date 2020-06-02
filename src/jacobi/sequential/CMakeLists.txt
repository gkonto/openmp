  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(PROJECT jacobi)

  INCLUDE_DIRECTORIES(${AUX_DIR})
  INCLUDE_DIRECTORIES(${TOOLS_DIR})

  SET(SOURCES
      main.cpp
      jacobi.cpp
      jacobi.hpp
      gnuplot_i.h
      gnuplot_i.cpp
      gnuplot_i.hpp
      ${AUX_DIR}/auxiliaries.hpp
      ${AUX_DIR}/auxiliaries.cpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()


