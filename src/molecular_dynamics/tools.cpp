#include <math.h>
#include <iostream>
#include "auxiliaries.hpp"
#include "tools.hpp"

void getSpatialDimension(char **argv, int argc, int &nd) {
  // Get the spatial dimension.
  if (1 < argc) {
      read_value<int>(argv[1], nd);
  } else {
    std::cout << std::endl;
    std::cout << "  Enter ND, the spatial dimension (2 or 3)." << std::endl;
    scanf("%d", &nd);
  }
}

void getNumberOfParticles(char **argv, int argc, int &np) {
  if (2 < argc) {
      read_value<int>(argv[2], np);
  } else {
    std::cout << std::endl;
    std::cout << "  Enter NP, the number of particles (500, for instance)."
              << std::endl;
    scanf("%d", &np);
  }
}

void getNumberOfTimeSteps(char **argv, int argc, int &step_num) {
  if (3 < argc) {
    read_value(argv[3], step_num);
  } else {
    std::cout << std::endl;
    std::cout << "  Enter ND, the number of time steps (500 or 1000, for "
                 "instance)."
              << std::endl;
    scanf("%d", &step_num);
  }
}

void getTimeSteps(char **argv, int argc, double &dt) {
  if (4 < argc) {
      read_value<double>(argv[4], dt);
  } else {
    std::cout << std::endl;
    std::cout << "  Enter DT, the size of the time step (0.1, for instance)."
              << std::endl;
    scanf("%lf", &dt);
  }
}


void getNumOfThreads(char **argv, int argc, int &num_threads) {
  if (5 < argc) {
      read_value<int>(argv[5], num_threads);
  } else {
    std::cout << std::endl;
    std::cout << "  Enter NumThreads 1-4" << std::endl;
    scanf("%d", &num_threads);
  }
}



