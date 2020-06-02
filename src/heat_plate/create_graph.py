#!/bin/python3
import matplotlib.pyplot as plt
import json
import sys
from os.path import dirname, abspath, join
split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import decorate_title


def update_lines(entry):
    split = entry[0].split()
    key = None
    try:
        key = split[0] + "__" + split[2]
    except:
        key = split[0]

    if key not in lines:
        lines[key] = list()

    lines[key].append([split[1], entry[1]]);


def create_lines(d):
    for entry in d["Executions"]:
        update_lines(entry)


with open("result.json", 'r') as f:
    d = json.load(f)


lines = dict()
create_lines(d)

for key, data in lines.items():
    x_axis = [entry[0] for entry in data]
    y_axis = [entry[1] for entry in data]
    try:
        l= "Case: {} Threads Number: {}".format(key.split("/")[0], key.split("__")[1])
    except:
        l = "Case: {}".format(key.split("/")[0])

    plt.plot(x_axis, y_axis, label = l)
    plt.xlabel("Epsilon")
    plt.ylabel("Time (sec)")

fig = plt.figure(1)
fig.canvas.set_window_title("Heat Plate")
title = decorate_title(d["system"])
plt.title(title)
plt.legend()
plt.show()
