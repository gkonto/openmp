#!/bin/python
import os
import subprocess
import platform
import re
import time
import json

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



class Case:
    def __init__(self, name, results):
        self.name_ = name
        self.results_ = results



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


def executeCpp(prog, val, thread):
    # create a pipe to a child process
    data, temp = os.pipe()

    # write to STDIN as a byte object(covert string
    # to bytes with encoding utf8)
    #os.write(temp, bytes("5 10\n", "utf-8"));
    os.write(temp, bytes("5 10\n"))
    os.close(temp)

    # store output of the program as a byte string in s
    start_time = time.time()
    try:
        s = subprocess.check_output("{} {} {} {} {}".format(prog, val[0], val[1], val[2], thread), stdin = data, shell = True)
    except:
        s = subprocess.check_output("{} {} {} {}".format(prog, val[0], val[1], val[2]), stdin = data, shell = True)

    t = time.time() - start_time

    print(t)
    # decode s to a normal string
    #value = int(s.decode("utf-8").strip('\n'))
    return t


class Measurement:
    def __init__(self, variation):
        self.variation_ = variation
        self.times_ = list()

    def __eq__(self, key):
        return self.variation_ == key

    def __dict__(self):
        return dict()

    def __repr__(self):
        return ""


def find_in_measurements(measurements, val):
    for m in measurements:
        if m == val:
            return m
    return None


if __name__=="__main__":

    if platform.system() != "Linux":
        print("Error: This script runs only in linux systems!!");

    # Gather all implemented fibonacci variations
    variations = os.listdir(os.path.dirname(os.path.abspath(__file__)))
    programs = list()
    for variation in variations:
        abspath = os.path.abspath(variation)
        if (os.path.isdir(abspath)):
            full_path_file = os.path.join(abspath, "build" , "mat_mul")
            if (os.path.isfile(full_path_file)):
                programs.append(full_path_file)
            else:
                print("Error: The following file should exist:")
                print(full_path_file)

    # Get cpu details
    system_details = get_processor_name()
    ram_details = get_ram();

    # accumulate dictionaries
    system_details.update(ram_details)

    print(system_details)

    # Execute variations
    min_val = 20
    max_val = 37
    min_thread = 1
    max_thread = 4
    dimension_cases = [
            [400, 400, 400],
            [800, 800, 800],
            [900, 900, 900],
            [1000, 1000, 1000],
            [1100, 1100, 1100],
            [1200, 1200, 1200],
            [1300, 1300, 1300],
            [1400, 1400, 1400],
            [1500, 1500, 1500],
            [1600, 1600, 1600]
            #[3200, 3200, 3200]
            ]

    details = dict()
    measurements = list()
    dimensions = list()
    for prog in sorted(programs): #Sorted reversed: [sequential, c1, c2...]
        variation = prog.split('/')[-3]
        for i, thread in enumerate(range(min_thread, max_thread)):
            tmp = "Case: " + variation + " Threads: " + str(thread)
            for val in dimension_cases:
                t = executeCpp(prog, val, thread)

                found = find_in_measurements(measurements, tmp)
                if found == None:
                    found = Measurement(tmp)
                    measurements.append(found)

                f = find_in_measurements(dimensions, str(val))
                if f == None:
                    dimensions.append(str(val))
                found.times_.append(t)

            if (prog.split('/')[-3] == 'sequential'):
                break

    details['system details'] = system_details
    details['legends'] = [o.__dict__ for o in measurements]
    details['dimensions'] = dimensions

    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)
