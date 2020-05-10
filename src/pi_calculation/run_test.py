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
        ["sequential", [100000]],
        ["sequential", [1000000]],
        #["sequential", [10000000]],
        #["sequential", [100000000]],
        #["sequential", [1000000000]],
        ["c1", [1000, 1]],
        ["c1", [10000, 1]],
        ["c1", [1000, 2]],
        ["c1", [10000, 2]],
        #["c2", [1000, 2]],
        #["c2", [10000, 2]]
        ["c3", [1000, 1]],
        ["c3", [10000, 1]],
        ["c3", [1000, 2]],
        ["c3", [10000, 2]]
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
    t = time.time() - start_time

    print(t)
    # decode s to a normal string
    #value = int(s.decode("utf-8").strip('\n'))
    return t




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




