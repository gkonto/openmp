#ifndef TOOLS_HPP
#define TOOLS_HPP
extern void  getSpatialDimension(char **argv, int argc, int &nd);
extern void  getNumberOfParticles(char **argv, int argc, int &np);
extern void  getNumberOfTimeSteps(char **argv, int argc, int &step_num);
extern void  getTimeSteps(char **argv, int argc, double &dt);
extern void  getNumOfThreads(char **argv, int argc, int &num_threads);

/******************************************************************************/
/*
Purpose:

DIST computes the displacement (and its norm) between two particles.

Parameters:
Input, int ND, the number of spatial dimensions.
Input, double R1[ND], R2[ND], the positions of the particles.
Output, double DR[ND], the displacement vector.
Output, double D, the Euclidean norm of the displacement.
*/

extern double dist(int nd, double r1[], double r2[], double dr[]);
#endif
