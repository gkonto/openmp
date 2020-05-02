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
                x_axis.append(x)
                y_axis.append(d['executions'][key]['threads num'][thread]['fib(x)'][x][0])
            m.x_axis.extend([x for _,x in sorted(zip(y_axis, x_axis))])
            m.y_axis.extend([y for y, _ in sorted(zip(y_axis, x_axis))])
            lines.append(m)
    return lines


if __name__=="__main__":

    lines = create_lines()


    for line in lines:
        # plotting the line 1 points
        plt.plot(line.x_axis, line.y_axis, label = "Case: {} Threads number: {}".format(line.name, line.threads_num))

        # naming the x axis
        plt.xlabel('Value x for fib(x)')
        # naming the y axis
        plt.ylabel('Time (s)')
        # giving a title to my graph
        plt.title('Fibonacci Comparison Cases')

    # show a legend on the plot
    plt.legend()

    # function to show the plot
    plt.show()
