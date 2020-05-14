#!/bin/python
import platform
import time
import json
import subprocess
import os
import re
from os.path import abspath, dirname, isdir, isfile, join
from os import listdir

variants = [

             ["sequential", [1000000]],
             ["sequential", [2000000]],
             ["sequential", [4000000]],
             ["sequential", [8000000]],
             ["sequential", [16000000]],
             ["sequential", [32000000]],
             ["sequential", [64000000]],
             ["sequential", [128000000]],
             ["sequential", [256000000]],
             ["sequential", [512000000]],
             ["sequential", [1024000000]],

             ["c1", [1000000   , 1]],
             ["c1", [2000000   , 1]],
             ["c1", [4000000   , 1]],
             ["c1", [8000000   , 1]],
             ["c1", [16000000  , 1]],
             ["c1", [32000000  , 1]],
             ["c1", [64000000  , 1]],
             ["c1", [128000000 , 1]],
             ["c1", [256000000 , 1]],
             ["c1", [512000000 , 1]],
             ["c1", [1024000000, 1]],
             ["c1", [1000000   , 2]],
             ["c1", [2000000   , 2]],
             ["c1", [4000000   , 2]],
             ["c1", [8000000   , 2]],
             ["c1", [16000000  , 2]],
             ["c1", [32000000  , 2]],
             ["c1", [64000000  , 2]],
             ["c1", [128000000 , 2]],
             ["c1", [256000000 , 2]],
             ["c1", [512000000 , 2]],
             ["c1", [1024000000, 2]],
             ["c1", [1000000   , 3]],
             ["c1", [2000000   , 3]],
             ["c1", [4000000   , 3]],
             ["c1", [8000000   , 3]],
             ["c1", [16000000  , 3]],
             ["c1", [32000000  , 3]],
             ["c1", [64000000  , 3]],
             ["c1", [128000000 , 3]],
             ["c1", [256000000 , 3]],
             ["c1", [512000000 , 3]],
             ["c1", [1024000000, 3]],
             ["c1", [1000000   , 4]],
             ["c1", [2000000   , 4]],
             ["c1", [4000000   , 4]],
             ["c1", [8000000   , 4]],
             ["c1", [16000000  , 4]],
             ["c1", [32000000  , 4]],
             ["c1", [64000000  , 4]],
             ["c1", [128000000 , 4]],
             ["c1", [256000000 , 4]],
             ["c1", [512000000 , 4]],
             ["c1", [1024000000, 4]],

             ["c3", [1000000   , 1]],
             ["c3", [2000000   , 1]],
             ["c3", [4000000   , 1]],
             ["c3", [8000000   , 1]],
             ["c3", [16000000  , 1]],
             ["c3", [32000000  , 1]],
             ["c3", [64000000  , 1]],
             ["c3", [128000000 , 1]],
             ["c3", [256000000 , 1]],
             ["c3", [512000000 , 1]],
             ["c3", [1024000000, 1]],
             ["c3", [1000000   , 2]],
             ["c3", [2000000   , 2]],
             ["c3", [4000000   , 2]],
             ["c3", [8000000   , 2]],
             ["c3", [16000000  , 2]],
             ["c3", [32000000  , 2]],
             ["c3", [64000000  , 2]],
             ["c3", [128000000 , 2]],
             ["c3", [256000000 , 2]],
             ["c3", [512000000 , 2]],
             ["c3", [1024000000, 2]],
             ["c3", [1000000   , 3]],
             ["c3", [2000000   , 3]],
             ["c3", [4000000   , 3]],
             ["c3", [8000000   , 3]],
             ["c3", [16000000  , 3]],
             ["c3", [32000000  , 3]],
             ["c3", [64000000  , 3]],
             ["c3", [128000000 , 3]],
             ["c3", [256000000 , 3]],
             ["c3", [512000000 , 3]],
             ["c3", [1024000000, 3]],
             ["c3", [1000000   , 4]],
             ["c3", [2000000   , 4]],
             ["c3", [4000000   , 4]],
             ["c3", [8000000   , 4]],
             ["c3", [16000000  , 4]],
             ["c3", [32000000  , 4]],
             ["c3", [64000000  , 4]],
             ["c3", [128000000 , 4]],
             ["c3", [256000000 , 4]],
             ["c3", [512000000 , 4]],
             ["c3", [1024000000, 4]],

             ["c4", [1000000   , 1]],
             ["c4", [2000000   , 1]],
             ["c4", [4000000   , 1]],
             ["c4", [8000000   , 1]],
             ["c4", [16000000  , 1]],
             ["c4", [32000000  , 1]],
             ["c4", [64000000  , 1]],
             ["c4", [128000000 , 1]],
             ["c4", [256000000 , 1]],
             ["c4", [512000000 , 1]],
             ["c4", [1024000000, 1]],
             ["c4", [1000000   , 2]],
             ["c4", [2000000   , 2]],
             ["c4", [4000000   , 2]],
             ["c4", [8000000   , 2]],
             ["c4", [16000000  , 2]],
             ["c4", [32000000  , 2]],
             ["c4", [64000000  , 2]],
             ["c4", [128000000 , 2]],
             ["c4", [256000000 , 2]],
             ["c4", [512000000 , 2]],
             ["c4", [1024000000, 2]],
             ["c4", [1000000   , 3]],
             ["c4", [2000000   , 3]],
             ["c4", [4000000   , 3]],
             ["c4", [8000000   , 3]],
             ["c4", [16000000  , 3]],
             ["c4", [32000000  , 3]],
             ["c4", [64000000  , 3]],
             ["c4", [128000000 , 3]],
             ["c4", [256000000 , 3]],
             ["c4", [512000000 , 3]],
             ["c4", [1024000000, 3]],
             ["c4", [1000000   , 4]],
             ["c4", [2000000   , 4]],
             ["c4", [4000000   , 4]],
             ["c4", [8000000   , 4]],
             ["c4", [16000000  , 4]],
             ["c4", [32000000  , 4]],
             ["c4", [64000000  , 4]],
             ["c4", [128000000 , 4]],
             ["c4", [256000000 , 4]],
             ["c4", [512000000 , 4]],
             ["c4", [1024000000, 4]],

             ["c5", [1000000   , 1]],
             ["c5", [2000000   , 1]],
             ["c5", [4000000   , 1]],
             ["c5", [8000000   , 1]],
             ["c5", [16000000  , 1]],
             ["c5", [32000000  , 1]],
             ["c5", [64000000  , 1]],
             ["c5", [128000000 , 1]],
             ["c5", [256000000 , 1]],
             ["c5", [512000000 , 1]],
             ["c5", [1024000000, 1]],
             ["c5", [1000000   , 2]],
             ["c5", [2000000   , 2]],
             ["c5", [4000000   , 2]],
             ["c5", [8000000   , 2]],
             ["c5", [16000000  , 2]],
             ["c5", [32000000  , 2]],
             ["c5", [64000000  , 2]],
             ["c5", [128000000 , 2]],
             ["c5", [256000000 , 2]],
             ["c5", [512000000 , 2]],
             ["c5", [1024000000, 2]],
             ["c5", [1000000   , 3]],
             ["c5", [2000000   , 3]],
             ["c5", [4000000   , 3]],
             ["c5", [8000000   , 3]],
             ["c5", [16000000  , 3]],
             ["c5", [32000000  , 3]],
             ["c5", [64000000  , 3]],
             ["c5", [128000000 , 3]],
             ["c5", [256000000 , 3]],
             ["c5", [512000000 , 3]],
             ["c5", [1024000000, 3]],
             ["c5", [1000000   , 4]],
             ["c5", [2000000   , 4]],
             ["c5", [4000000   , 4]],
             ["c5", [8000000   , 4]],
             ["c5", [16000000  , 4]],
             ["c5", [32000000  , 4]],
             ["c5", [64000000  , 4]],
             ["c5", [128000000 , 4]],
             ["c5", [256000000 , 4]],
             ["c5", [512000000 , 4]],
             ["c5", [1024000000, 4]],

             ["c6", [1000000   , 1]],
             ["c6", [2000000   , 1]],
             ["c6", [4000000   , 1]],
             ["c6", [8000000   , 1]],
             ["c6", [16000000  , 1]],
             ["c6", [32000000  , 1]],
             ["c6", [64000000  , 1]],
             ["c6", [128000000 , 1]],
             ["c6", [256000000 , 1]],
             ["c6", [512000000 , 1]],
             ["c6", [1024000000, 1]],
             ["c6", [1000000   , 2]],
             ["c6", [2000000   , 2]],
             ["c6", [4000000   , 2]],
             ["c6", [8000000   , 2]],
             ["c6", [16000000  , 2]],
             ["c6", [32000000  , 2]],
             ["c6", [64000000  , 2]],
             ["c6", [128000000 , 2]],
             ["c6", [256000000 , 2]],
             ["c6", [512000000 , 2]],
             ["c6", [1024000000, 2]],
             ["c6", [1000000   , 3]],
             ["c6", [2000000   , 3]],
             ["c6", [4000000   , 3]],
             ["c6", [8000000   , 3]],
             ["c6", [16000000  , 3]],
             ["c6", [32000000  , 3]],
             ["c6", [64000000  , 3]],
             ["c6", [128000000 , 3]],
             ["c6", [256000000 , 3]],
             ["c6", [512000000 , 3]],
             ["c6", [1024000000, 3]],
             ["c6", [1000000   , 4]],
             ["c6", [2000000   , 4]],
             ["c6", [4000000   , 4]],
             ["c6", [8000000   , 4]],
             ["c6", [16000000  , 4]],
             ["c6", [32000000  , 4]],
             ["c6", [64000000  , 4]],
             ["c6", [128000000 , 4]],
             ["c6", [256000000 , 4]],
             ["c6", [512000000 , 4]],
             ["c6", [1024000000, 4]]
 ]

def get_ram():
    ret = dict()
    if platform.system() == "Linux":
        command = "cat /proc/meminfo"
        all_info = subprocess.check_output(command, shell=True).strip()
        lines = all_info.split("\n")
        for line in lines:
            if "MemTotal" in line:
                ret["MemTotal"] = re.sub(".*MemTotal.*:", "", line, 1).strip()

    return ret



# FIXME this function is duplicate in all examples
# create a library and add all duplicate files
def get_processor_name():
    ret = dict()
    if platform.system() == "Windows":
        return platform.processor()
    elif platform.system() == "Linux":
        command = "cat /proc/cpuinfo"
        all_info = subprocess.check_output(command, shell=True).strip()
        info = ""

        for line in all_info.split("\n"):
            if "model name" in line:
                ret["model name"] = re.sub(".*model name.*:", "", line, 1).strip()
            elif "cpu cores" in line:
                ret["cpu cores"] = re.sub(".*cpu cores.*:", "", line, 1).strip()
    return ret


def executeProgram(prog):
    # create a pipe to a child process
    data, temp = os.pipe()

    # write to STDIN as a byte object(covert string
    # to bytes with encoding utf8)
    #os.write(temp, bytes("5 10\n", "utf-8"));
    os.write(temp, bytes("5 10\n"))
    os.close(temp)

    # store output of the program as a byte string in s
    start_time = time.time()
    s = subprocess.check_output(prog, stdin = data, shell = True)

    # decode s to a normal string
    value = s.decode("utf-8").split('\n')
    return float(value[0].split()[-1])


if platform.system() != "Linux" :
    print("Error: This script runs only in linux systems!!");

this_path = dirname(abspath(__file__))

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

times = [[program, round(executeProgram(program), 3)] for program in programs]
details = dict()
details["system"] = system_details
details["system"]["MemTotal"] = ram_details["MemTotal"]
details["Executions"] = times
j = json.dumps(details, indent = 1)

with open("result.json", 'w') as outfile:
    outfile.write(j)




