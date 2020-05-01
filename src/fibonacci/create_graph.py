#!/bin/python3
import matplotlib.pyplot as plt
from collections import namedtuple
import json


def create_lines():
    with open("result.json", 'r') as f:
        d = json.load(f)

    lines = list()
    for key in d['executions']:
        Line = namedtuple("Line", "name")
        for thread in d['executions'][key]['threads num']:
            Line = namedtuple("Line", "name threads_num x_axis y_axis")
            m = Line(key, thread, list(), list())
            x_axis = list()
            y_axis = list()
            for x in d['executions'][key]['threads num'][thread]['fib(x)']:
                m.x_axis.append(x)
                m.y_axis.append(d['executions'][key]['threads num'][thread]['fib(x)'][x][0])
            lines.append(m)
    return lines


if __name__=="__main__":

    lines = create_lines()


    for line in lines:
        # plotting the line 1 points
        plt.plot(line.x_axis, line.y_axis, label = "{} {}".format(line.name, line.threads_num))

        # naming the x axis
        plt.xlabel('Value')
        # naming the y axis
        plt.ylabel('Time')
        # giving a title to my graph
        plt.title('Two lines on same graph!')

    # show a legend on the plot
    plt.legend()

    # function to show the plot
    plt.show()
