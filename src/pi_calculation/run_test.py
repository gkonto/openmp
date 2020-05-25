#!/bin/python
import platform
import time
import json
import subprocess
import os
import re
from os.path import abspath, dirname, isdir, isfile, join
from os import listdir

import sys
split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import get_processor_name, get_ram, execute_program, get_doubles

THIS_PATH = dirname(abspath(__file__))
VAR_FILE  = join(THIS_PATH, "run_variations.json")

if __name__=="__main__":
    if platform.system() != "Linux" :
        print("Error: This script runs only in linux systems!!");

    variants = None
    with open(VAR_FILE, 'r') as fp:
        variants  = json.load(fp)

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    #Gather all program variations found
    programs = list()
    for variant in variants:
        prog = join(variant[0], "build", "pi")
        args = ""
        for arg in variant[1]:
            args += str(arg) + " "

        programs.append(prog + " " + args)

    times = [[program, float(get_doubles(execute_program(program))[0])] for program in programs]
    details = dict()
    details["system"] = system_details
    details["system"]["MemTotal"] = ram_details["MemTotal"]
    details["Executions"] = times
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)




