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
    def __init__(self, case, spatial_dimension, num_of_particles, step_num, dt, num_threads):
        self.__case = case
        self.__prog_path = join(THIS_PATH, case, "build/md")
        self.__num_of_particles = num_of_particles
        self.__spatial_dimension = spatial_dimension
        self.__step_num = step_num
        self.__dt = dt
        self.__num_threads = num_threads
        self.__exec_time = 0.0

    def __repr__(self):
        if "seq" in self.__case:
            return "Case: {}".format(self.__case)
        else:
            return "Case: {} Num Threads: {}".format(self.__case, self.__num_threads)

    @property
    def spatial_dimension(self):
        return self.__spatial_dimension

    @property
    def case(self):
        return self.__case

    @property
    def prog_path(self):
        return self.__prog_path

    @property
    def num_of_particles(self):
        return self.__num_of_particles

    @property
    def step_num(self):
        return self.__step_num

    @property
    def dt(self):
        return self.__dt

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
        print("Could not open run_variatons.json")
        exit(1)

    executions = OrderedDict()
    gen_exp = (entry for entry in variants)
    for entry in gen_exp:
        e = None
        prog_w_var = None

        try:
            e = Entry(entry[0], entry[1][0], entry[1][1], entry[1][2], entry[1][3], entry[1][4])
            prog_w_var = "{} {} {} {} {} {}".format(e.prog_path, e.spatial_dimension, e.num_of_particles, e.step_num, e.dt, e.num_threads)
        except:
            e = Entry(entry[0], entry[1][0], entry[1][1], entry[1][2], entry[1][3], 1)
            prog_w_var = "{} {} {} {} {}".format(e.prog_path, e.spatial_dimension, e.num_of_particles, e.step_num, e.dt)

        s = execute_program(prog_w_var)
        times = get_doubles(s)
        time = times[-6]

        e.exec_time = time

        if str(e) not in executions:
            executions[str(e)] = list()
        executions[str(e)].append([str(e.spatial_dimension), str(e.num_of_particles), str(e.step_num), str(e.dt), float(e.exec_time)])

    details = dict()
    details["system"] = system_details
    details["system"]["Memtotal"] = ram_details["MemTotal"]
    details["Executions"] = executions
    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)
