#!/bin/python3
import matplotlib.pyplot as plt
import json


def update_lines(entry):
    split = entry[0].split()
    key = None
    try:
        key = split[0] + "_" + split[2]
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
    print(key)
    print(data)
    x_axis = [entry[0] for entry in data]
    y_axis = [entry[1] for entry in data]
    try:
        l= "Case: {} Threads Number: {}".format(key.split("/")[0], key.split("_")[1])
    except:
        l = "Case: {}".format(key.split("/")[0])
    print(x_axis)
    print(y_axis)
    print(l)
    plt.plot(x_axis, y_axis, label = l)
    plt.xlabel("Number of integration steps")
    plt.ylabel("Time (sec)")
    plt.title("PI calculation")

plt.legend()
plt.show()
