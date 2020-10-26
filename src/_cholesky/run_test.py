#!/bin/python
import platform
import json
import subprocess
import re
import os
from os.path import abspath, dirname, isdir, isfile, join
from os import listdir

import sys
split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import get_processor_name, get_ram, execute_program, get_doubles


if __name__=="__main__":
    if platform.system() != "Linux":
        print("Error: This script runs only in linux systems!!")
        exit(1);

    variants = list()
    with open("run_variations.json", 'r') as f:
        variants = json.load(f)

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram()

    # accumulate dictionaries
    system_details.update(ram_details)

    programs = [join(variant[0], "build", "cholesky") + " " + " ".join(map(str, variant[1])) for variant in variants]


    times = [[program, float(get_doubles(execute_program(program))[-1])] for program in programs]

    details = dict()
    details["system"] = system_details
    details["system"]["MemTotal"] = ram_details["MemTotal"]
    details["Executions"] = times
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)

