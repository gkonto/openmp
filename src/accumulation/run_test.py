#!/bin/python
import platform
import time
import json
import os
from os.path import abspath, dirname, isdir, isfile, join
from os import listdir

import sys

split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
final = join(accum, "auxiliaries")

sys.path.insert(1, final)
from py_aux import get_processor_name, get_ram, execute_program

variants = list()

with open("run_variations.json", 'r') as f:
    variants = json.load(f)

if __name__=="__main__":
    if platform.system() != "Linux" :
        print("Error: This script runs only in linux systems!!")
    this_path = dirname(abspath(__file__))

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    programs = list()
    for variant in variants:
        prog = join(variant[0], "build", "accumulate")
        args = ""

        for arg in variant[1]:
            args += str(arg) + " "
        programs.append(prog + " " + args)
    output = [[program, execute_program(program)] for program in programs]

    details = dict()
    details["system"] = system_details
    details["system"]["MemTotal"] = ram_details["MemTotal"]
    details["Executions"] = output
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)

