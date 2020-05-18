#!/bin/python3
import matplotlib.pyplot as plt
import json
import numpy as np


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


def getLabel(x):
    v = ""
    if "sequential" in x:
        v = x.split("/")[0]
    else:
        v = "{} Num Threads: {}".format(x.split("/")[0], x.split()[-1])
    return v


def read_json():
    with open("result.json", 'r') as f:
        d = json.load(f)

    legends = list()
    all_val = list()

    title = ""
    for label, val in d['system'].items():
        title += label + ": " + val + "\n"

    legends = [m[0] for m in d["Executions"]]
    all_val = [float(m[1][1].split()[-1]) for m in d["Executions"]]

    return tuple(legends), all_val, title

legends, vals, title = read_json()
variation = [getLabel(x) for x in legends]
print(variation)

y_pos = np.arange(len(variation))

fig = plt.figure(num="Accumulation number")

plt.bar(y_pos, vals, align = 'center', alpha = 0.5)
plt.xticks(y_pos, variation)
plt.ylabel("Execution Time (sec)")
plt.title(title)
plt.show()

