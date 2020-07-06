#!/bin/python
import os
import subprocess
import sys
import platform
import re
import time
import json
from collections import defaultdict, OrderedDict
from os.path import abspath, dirname, join
from os import listdir

split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import get_processor_name, get_ram, execute_program, get_doubles

THIS_PATH = dirname(abspath(__file__))
VAR_FILE  = join(THIS_PATH, "run_variations.json")

class Entry:
    def __init__(self, case, num_threads):
        self.__case = case
        self.__prog_path = join(THIS_PATH, case, "build/add_arrays")
        self.__num_threads = num_threads
        self.__exec_time  = 0.0

    def __repr__(self):
        if "seq" in self.__case:
            return "Case: {}".format(self.__case)
        else:
            return "Case: {} Num Threads: {}".format(self.__case, self.__num_threads)

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
        print("Error: This script runs only in linux systems!!");

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    executions = OrderedDict()

    with open(VAR_FILE, 'r') as fp:
        data = json.load(fp)
        gen_exp = (entry for entry in data)
        for entry in gen_exp:
            e = None
            prog_w_var = None
            try:
                e = Entry(entry[0], entry[1][1])
                prog_w_var = "{} {} {}".format(e.prog_path, entry[1][0], e.num_threads)
            except:
                e = Entry(entry[0], 1)
                prog_w_var = "{} {}".format(e.prog_path, entry[1][0])

            s = execute_program(prog_w_var)
            time = get_doubles(s)
            e.exec_time = time[0]
            if str(str(e)) not in executions:
                executions[str(e)] = list()

            executions[str(e)].append([str(entry[1][0]), float(e.exec_time)])

        prog_details = dict()
        prog_details["Results"] = executions
        prog_details["System Details"] = system_details
        j = json.dumps(prog_details, indent = 1)

        with open("result.json", 'w') as outfile:
            outfile.write(j)
