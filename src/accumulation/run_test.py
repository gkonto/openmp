#!/bin/python
import platform
import time
import json
import os
import sys
from os.path import abspath, dirname, isdir, isfile, join
from os import listdir

split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
final = join(accum, "auxiliaries")

sys.path.insert(1, final)
from py_aux import get_processor_name, get_ram, execute_program, get_doubles

variants = list()

with open("run_variations.json", 'r') as f:
    variants = json.load(f)

if __name__=="__main__":
    if platform.system() != "Linux" :
        print("Error: This script runs only in linux systems!!")

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)
    programs = [join(variant[0], "build", "accumulate") + " " + " ".join(map(str, variant[1])) for variant in variants]
    output = [[program, float(get_doubles(execute_program(program))[1])] for program in programs]
    print(output)

    details = dict()
    details["system"] = system_details
    details["system"]["MemTotal"] = ram_details["MemTotal"]
    details["Executions"] = output
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)

