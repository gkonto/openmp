#!/usr/bin/python3
#Example code (Python):

#from scipy import random, linalg
import numpy
import argparse


if __name__=="__main__":
    parser = argparse.ArgumentParser(description = "This script creates a summetric, positive definite matrix of specify dimension")
    parser.add_argument("dimension", type=int, help = "An integer as rectangular matrix dimension")
    args = parser.parse_args()

    matrixSize = args.dimension
    A = random.rand(matrixSize,matrixSize)
    B = numpy.dot(A,A.transpose())

    if numpy.all(numpy.linalg.eigvals(B)):
        numpy.savetxt(f"{args.x}.csv", B, delimiter=" ", fmt = "%.2f")
        print("Success!!!")
    else:
        print("Failure...")

