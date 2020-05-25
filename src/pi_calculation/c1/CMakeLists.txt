  cmake_minimum_required(VERSION 2.8.7)

  PROJECT(sequential)
  SET(CMAKE_CXX_STANDARD 14)

  ADD_DEFINITIONS("-g -Wall -Wextra -O0 -Wunreachable-code")
  ADD_SUBDIRECTORY(integrate)

  SET(ROOT_DIR ../../)
  SET(AUX_DIR ${ROOT_DIR}/auxiliaries)
  SET(PROJECT pi)
  INCLUDE_DIRECTORIES(${AUX_DIR})

  SET(SOURCES
      run.cpp
      ${AUX_DIR}/auxiliaries.cpp
      ${AUX_DIR}/auxiliaries.hpp
      )

  ADD_EXECUTABLE(${PROJECT} ${HEADERS} ${SOURCES})

  TARGET_LINK_LIBRARIES(${PROJECT} integrate)
  #TARGET_LINK_LIBRARIES(run_fib aparser)

 find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(pi PUBLIC OpenMP::OpenMP_CXX)
endif()


