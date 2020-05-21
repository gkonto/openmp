#!/bin/python
import os
import re
import platform
import json
import sys
from collections import defaultdict, namedtuple
from os.path import abspath, dirname, isdir, isfile, join, exists

split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import get_processor_name, get_ram, execute_program

CONFIG = "run_variations.json"
Entry = namedtuple("Entry", "value exec_time")

class Input:

    def __init__(self, variation, program, input_data, exec_time):
        self.__variation = variation #sequential, c1, c2 etc
        self.__program = program #full path to executable
        self.__exec_val  = input_data[0]

        try:
            self.__num_threads = input_data[1]
        except:
            self.__num_threads = 1

        self.__exec_time = exec_time # execution time

    @property
    def variation(self):
        return self.__variation

    @property
    def num_threads(self):
        return self.__num_threads

    @property
    def exec_val(self):
        return self.__exec_val

    @property
    def exec_time(self):
        return self.__exec_time

    @property
    def program(self):
        return self.__program

    def __hash__(self):
        return hash(self.variation + str(self.num_threads))

    def __eq__(self, other):
        return hash(other) == hash(other)

    def __repr__(self):
        return self.variation

    def __str__(self):
        try:
            return "Case: {}\n\tNum Threads: {}\n\tValue: {}\n\tExec Time: {}".format(self.variation, self.num_threads, self.exec_val, self.exec_time)
        except:
            return "Case: {}\n\tValue: {}\n\tExec Time: {}".format(self.variation, self.exec_val, self.exec_time)

    def key_rep(self):
        return "Case:" + " " + self.variation + " " +\
                "Num threads: " + str(self.num_threads)


if __name__=="__main__":
    if platform.system() != "Linux":
        print("Error: This script runs only in linux systems!!");

    # Gather all implemented fibonacci variations
    this_path = dirname(abspath(__file__))
    variations_file = join(this_path, CONFIG)
    data = None

    with open(variations_file, 'r') as fp:
        data = json.load(fp)

    gen_exp = (i for i in data)
    results = defaultdict(list)

    for d in gen_exp:
        prog_path = join(this_path, d[0], "build/run_fib")

        if not exists(prog_path):
            print("Program does not exist")
            continue

        inp = Input(d[0], prog_path, d[1], 0.0)

        value = None
        try:
            value = execute_program("{} {} {}".format(inp.program, inp.exec_val, inp.num_threads))
        except:
            value = execute_program("{} {}".format(inp.program, inp.exec_val))

        for entry in value:
            if "Time" in entry:
                inp.exec_time = re.findall('-?\ *[0-9]+\.?[0-9]*(?:[Ee]\ *-?\ *[0-9]+)?', entry)[0]

        results[inp.key_rep()].append(Entry(inp.exec_val, inp.exec_time))

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    # Program details
    prog_details = dict()
    prog_details["Results"] = results
    prog_details["System Details"] = system_details

    j = json.dumps(prog_details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)
