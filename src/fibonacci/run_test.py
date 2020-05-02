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
    s = subprocess.check_output("{} {} {}".format(prog, val, thread), stdin = data, shell = True)
    t = time.time() - start_time

    # decode s to a normal string
    value = int(s.decode("utf-8").strip('\n'))
    return t, value


if __name__=="__main__":

    if platform.system() != "Linux":
        print("Error: This script runs only in linux systems!!");

    # Gather all implemented fibonacci variations
    variations = os.listdir(os.path.dirname(os.path.abspath(__file__)))
    programs = list()
    for variation in variations:
        abspath = os.path.abspath(variation)
        if (os.path.isdir(abspath)):
            full_path_file = os.path.join(abspath, "build" , "run_fib")
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

    prog_details = dict()
    for prog in programs:
        prog_details[prog.split('/')[-3]] = dict()
        threads = dict()
        threads["threads num"] = dict();
        for thread in range(min_thread, max_thread):
            times = dict()
            times['fib(x)'] = dict()
            for val in range(min_val, max_val):
                t, value = executeCpp(prog, val, thread)
                times['fib(x)'][val] = [t, value]
            threads["threads num"][thread] = times
            if (prog.split('/')[-3] == 'sequential'):
                break
        prog_key = prog.split('/')[-3]
        prog_details[prog_key] = threads
    details = dict()
    details['system details'] = system_details
    details['executions'] = prog_details

    j = json.dumps(details, indent = 1)

    with open("result.json", 'w') as outfile:
        outfile.write(j)
