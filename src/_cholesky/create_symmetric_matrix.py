#!/usr/bin/python3
#Example code (Python):

from scipy import random, linalg
import numpy
import argparse

OUTFILE_NAME = "random_matrix"

if __name__=="__main__":
    parser = argparse.ArgumentParser(description = "This script creates a summetric, positive definite matrix of specify dimension")
    parser.add_argument("dimension", type=int, help = "An integer as rectangular matrix dimension")
    args = parser.parse_args()

    matrixSize = args.dimension
    A = random.rand(matrixSize,matrixSize)
    B = numpy.dot(A,A.transpose())
    #print('random positive semi-define matrix for today is\n', B)

    with open(f"{OUTFILE_NAME}_{matrixSize}", 'w') as fp:
        for line in B:
            for entry in line:
                fp.write(f'{entry} ')
            fp.write("\n")

    print(f"Results stored in {OUTFILE_NAME}_{matrixSize}")

