#!/bin/python3
import os
import subprocess

from os.path import dirname, abspath, join, isdir
from os import makedirs, chdir

examples = {
        "fibonacci" :["sequential", "c2"],
        "matrix_multiplication" : ["sequential", "c1", "c2"],
        "pi_calculation" : ["sequential", "c1", "c2", "c3", "c4", "c5", "c6"],
        "jacobi" : ["sequential", "c1"],
        "prime_numbers" : ["sequential", "c1"],
        "pi_calculation" : ["sequential", "c1", "c2", "c3", "c4", "c5", "c6"],
        "fft" : ["sequential", "c1"],
        "heat_plate" : ["sequential", "c1"],
        "fibonacci" : ["sequential", "c2"],
        "linked_list_traversal" : ["sequential", "c1", "c2", "c3"],
        "matrix_multiplication" : ["sequential", "c1", "c2"],
        "mandelbrot" : ["sequential", "c1"],
        "molecular_dynamics" : ["sequential", "c1"],
        "mergesort" : ["sequential", "c1", "c2"],
        "vectorization" : ["sequential", "c1"]
        }

if __name__=="__main__":
    this_path = dirname(abspath(__file__))
    variations_paths = [join(this_path, ex, variation) for ex in examples for variation in examples[ex]]
    for var in variations_paths:
        build_dir = join(var, "build")
        if isdir(build_dir):
            #TODO check output
            subprocess.check_output("make -C {}".format(build_dir), shell = True)
        else:
            makedirs(build_dir)
            chdir(build_dir)
            subprocess.check_output("cmake ../", shell = True)
            subprocess.check_output("make", shell = True)




