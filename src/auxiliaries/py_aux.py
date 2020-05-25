import platform
import subprocess
import re
import os
import time

#TODO decorate_title sound be in py_aux since it's duplicate
def decorate_title(details):
    title = ""
    title += details["model name"] + "\n"
    title += "Memory: " + details["MemTotal"] +  "\n"
    title += "CPU cores: " + details["cpu cores"]

    return title



def get_doubles(s):
    return re.findall('-?\ *[0-9]+\.?[0-9]*(?:[Ee]\ *-?\ *[0-9]+)?', s)

def execute_program(prog):
    # create a pipe to a child process
    data, temp = os.pipe()

    # write to STDIN as a byte object(covert string
    # to bytes with encoding utf8)
    #os.write(temp, bytes("5 10\n", "utf-8"));
    os.write(temp, bytes("5 10\n"))
    os.close(temp)

    # store output of the program as a byte string in s
    s = subprocess.check_output(prog, stdin = data, shell = True)

    # decode s to a normal string
    value = s.decode("utf-8")
    return value;


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

        for line in all_info.split("\n"):
            if "model name" in line:
                ret["model name"] = re.sub(".*model name.*:", "", line, 1).strip()
            elif "cpu cores" in line:
                ret["cpu cores"] = re.sub(".*cpu cores.*:", "", line, 1).strip()
    return ret




