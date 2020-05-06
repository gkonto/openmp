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

    labels = list()
    legends = list()
    all_val = list()
    for m in d["legends"]:
        labels.append(str(m["variation_"]));
        values = list()
        values = len(m["times_"]) * [-1]
        for case in m["times_"]:
            try:
                idx = legends.index(case)
            except:
                legends.append(case)
                idx = len(legends) - 1
            values[idx] = round(m["times_"][case], 3)
        all_val.append(values)


    return labels, legends, all_val


legends, labels, values = read_json()
print(labels)
print(legends)
print(values)
#labels = ["[100, 100, 100]", "[200, 200, 200]", "[300, 300, 300]"]
#legends  = ["seq", "c1_1", "c1_2", "c1_3"]
#values = [[1, 2, 3], [1, 2, 3], [1, 2, 3], [1, 2, 3]]



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
plt.show()
