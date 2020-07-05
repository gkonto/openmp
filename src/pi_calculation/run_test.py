#!/bin/python
import platform
import argparse
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


def parse_args():
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('input_file', metavar='input', type=str,  help=' a specific format json with the input')

    args = parser.parse_args()
    
    return args


if __name__=="__main__":

    args = parse_args()

    VAR_FILE  = join(THIS_PATH, args.input_file)

    if platform.system() != "Linux" :
        print("Error: This script runs only in linux systems!!");

    variants = None
    try:
        with open(VAR_FILE, 'r') as fp:
            variants  = json.load(fp)
    except:
        print("No {} exists! Aborting...".format(VAR_FILE))
        exit(1);

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    #Gather all program variations found
    programs = [join(variant[0], "build", "pi") + " " + " ".join(map(str, variant[1])) for variant in variants]
    times = [[program, float(get_doubles(execute_program(program))[0])] for program in programs]

    details = dict()
    details["system"] = system_details
    details["system"]["MemTotal"] = ram_details["MemTotal"]
    details["Executions"] = times
    j = json.dumps(details, indent = 1)

    with open("result_{}".format(args.input_file), 'w') as outfile:
        outfile.write(j)




