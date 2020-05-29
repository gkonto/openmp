#!/bin/python3
import matplotlib.pyplot as plt
from collections import namedtuple
import numpy as np
import matplotlib.pyplot as plt
import json
import sys
import matplotlib.pyplot as plt
import numpy as np

from os.path import dirname, abspath, join
split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import decorate_title


def read_json():
    with open("result.json", 'r') as f:
        d = json.load(f)

    groups = None
    bars_height = list()
    legends = [legend for legend in d["Executions"].keys()]
    bars_height = [[val[4] for val in heights] for key, heights in d["Executions"].items()]

    x_axis = ["/".join(vals[0:4]) for vals in next(iter(d["Executions"].values()))]
    groups = len(bars_height)
    title = decorate_title(d["system"])

    return groups, bars_height, x_axis, legends, title

if __name__=="__main__":
    groups, bar_heights, x_axis, legends, title = read_json()

    print("Groups")
    print(groups)
    print("Bar heights")
    print(bar_heights)
    print("x_axis")
    print(x_axis)
    print("Legends")
    print(legends)
    print("Title")
    print(title)

    #Set position of bar in X axis
    barWidth = 0.1
    rs = list()
    rs.append(np.arange(len(bar_heights[0])))
    for i in range(groups):
        rs.append([x + barWidth for x in rs[-1]])

    # Make the plot
    for idx, bars in enumerate(bar_heights):
        plt.bar(rs[idx], bars, width = barWidth, edgecolor='white', label=legends[idx])

    # Set title
    plt.title(title)

    # Add ticks on the middle of the group bars
    plt.xlabel("Spatial Dimension/Number of Particles/Time Steps/ Step size", fontweight='bold')
    plt.ylabel("Execution Time(seconds)", fontweight='bold')
    print(x_axis)
    plt.xticks([r + barWidth for r in range(len(bar_heights[0]))], x_axis)

    #Matrix title
    plt.gcf().canvas.set_window_title("Molecular Dynamics")

    # Create legend & Show Graphics
    plt.legend()
    plt.show()



