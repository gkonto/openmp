#!/bin/python3
import matplotlib.pyplot as plt
from collections import namedtuple
import numpy as np
import matplotlib.pyplot as plt
import json


import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def read_json():
    with open("result.json", 'r') as f:
        d = json.load(f)

    legends = list()
    all_val = list()
    dimensions = d["dimensions"]
    for m in d["legends"]:
        legends.append(m["variation_"])
        values = list()
        values = len(m["times_"]) * [-1]
        for i, time in enumerate(m["times_"]):
            values[i] = round(time, 3)
        all_val.append(values)


    print(dimensions)
    print(legends)
    print(all_val)
    return legends, dimensions, all_val


legends, labels, values = read_json()

# plot a barchart with error bar
fig, ax = plt.subplots()

plt.style.use('ggplot')

#fig, ax = plt.subplots()
index = np.arange(len(labels))
bar_width = 0.1
opacity = 0.8

for idx, legend in enumerate(legends):
    ax.bar(index + bar_width * idx, values[idx], bar_width, alpha=opacity, label=legend)

ax.set_xlabel('Matrix Dimensions')
ax.set_ylabel('Times (secs)')
ax.set_title('Matrix Multiplication')
ax.set_xticks(index + bar_width)
ax.set_xticklabels((label for label in labels))
ax.legend(ncol=3)
plt.xticks(rotation=90)
plt.show()
