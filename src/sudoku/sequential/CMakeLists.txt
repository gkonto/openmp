  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")

  #SET(ROOT_DIR ../../)
  #SET(FIB_DIR ${ROOT_DIR}/fibonacci/sequential/fib)
  #SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  #SET(EXAMPLE_DIR ${ROOT_DIR}/linked_list_traversal)

  # INCLUDE_DIRECTORIES(${FIB_DIR})
  # INCLUDE_DIRECTORIES(${AUX_DIR})
  # INCLUDE_DIRECTORIES(${EXAMPLE_DIR})

  SET(SOURCES
      run.cpp
      aux.cpp
      aux.hpp
      #${FIB_DIR}/fib.hpp
      #${FIB_DIR}/fib.cpp
      #${AUX_DIR}/auxiliaries.hpp
      #${AUX_DIR}/auxiliaries.cpp
      #${EXAMPLE_DIR}/tools/l_list.hpp
      #${EXAMPLE_DIR}/tools/l_list.cpp
      )

  ADD_EXECUTABLE(solve_sudoku ${HEADERS} ${SOURCES})

  FIND_PACKAGE(OpenMP)
if(OpenMP_CXX_FOUND)
    TARGET_LINK_LIBRARIES(solve_sudoku PUBLIC OpenMP::OpenMP_CXX)
endif()

