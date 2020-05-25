#!/bin/python3
import matplotlib.pyplot as plt
from collections import namedtuple
import json
import sys

from os.path import dirname, abspath, join
split = dirname(abspath(__file__)).split("/")
accum = "/".join(split[:-1])
aux_dir = join(accum, "auxiliaries")
sys.path.insert(1, aux_dir)
from py_aux import decorate_title



this_path = dirname(abspath(__file__))
RESULT_FILENAME = join(this_path, "result.json")

if __name__=="__main__":
    with open(RESULT_FILENAME, 'r') as f:
        d = json.load(f)

        for key, item in d["Results"].items():
            y_axis = [round(float(x_val[1]), 4) for x_val in item]
            x_axis = [y_val[0] for y_val in item]
            plt.plot(x_axis, y_axis, label = key);

        title = decorate_title(d["System Details"])
        plt.xlabel('Value x for fib(x)')
        plt.ylabel('Time (s)')
        plt.title(title)
        plt.gcf().canvas.set_window_title("Fibonacci")
        plt.legend()
        plt.show()
