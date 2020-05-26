#!/bin/python
import platform
import json
import os
from collections import OrderedDict
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

class Entry:
    def __init__(self, case, dimensions, num_threads):
        self.__case = case
        self.__prog_path = join(THIS_PATH, case, "build/mandelbrot")
        self.__num_threads = num_threads
        self.__dimensions = dimensions
        self.__exec_time  = 0.0

    def __repr__(self):
        if "seq" in self.__case:
            return "Case: {}".format(self.__case)
        else:
            return "Case: {} Num Threads: {}".format(self.__case, self.__num_threads)


    @property
    def dimensions(self):
        return self.__dimensions

    @property
    def prog_path(self):
        return self.__prog_path

    @property
    def case(self):
        return self.__case

    @property
    def num_threads(self):
        return self.__num_threads



if __name__=="__main__":
    if platform.system() != "Linux":
        print("Error: This sript run only in linux systems!!")

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    variants = None

    try:
        with open("run_variations.json", 'r') as f:
            variants = json.load(f)
    except:
        print("Could not open run_variations.json")
        exit(1)

    executions = OrderedDict()
    gen_exp = (entry for entry in variants)
    for entry in gen_exp:
        e = None
        prog_w_var = None

        try:
            e = Entry(entry[0], entry[1][0], entry[1][1])
            prog_w_var = "{} {} {}".format(e.prog_path, e.dimensions, e.num_threads)
        except:
            e = Entry(entry[0], entry[1][0], 1)
            prog_w_var = "{} {}".format(e.prog_path, e.dimensions)

        s = execute_program(prog_w_var)
        times = get_doubles(s)
        time = None
        if len(times) > 1:
            time = float(times[15])
        else:
            time = float(times[0])

        e.exec_time = time

        if str(e) not in executions:
            executions[str(e)] = list()
        executions[str(e)].append([str(e.dimensions), float(e.exec_time)])

    details = dict()
    details["system"] = system_details
    details["system"]["Memtotal"] = ram_details["MemTotal"]
    details["Executions"] = executions
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)

