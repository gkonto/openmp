  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(PROJECT prime_numbers)
  SET(PRIME prime)

  INCLUDE_DIRECTORIES(${AUX_DIR})
  INCLUDE_DIRECTORIES(${PRIME})

  SET(SOURCES
      run.cpp
      ${PRIME}/prime.hpp
      ${PRIME}/prime.cpp
      ${AUX_DIR}/auxiliaries.cpp
      ${AUX_DIR}/auxiliaries.hpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(${PROJECT} PUBLIC OpenMP::OpenMP_CXX)
endif()


