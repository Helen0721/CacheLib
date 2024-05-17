import os
import sys
import itertools
from collections import defaultdict
import re
import numpy as np
import random
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
from matplotlib.lines import Line2D
from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging

Lru_path = "/disk/CacheLib/examples/my_cache_1/build/my_cache_Lru"
Lru2Q_path = "/disk/CacheLib/examples/my_cache_1/build/my_cache_Lru2Q"
TinyLFU_path = "/disk/CacheLib/examples/my_cache_1/build/my_cache_TinyLFU"


ALGOS = ["Lru","Lru2Q","TinyLFU"]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]


REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 
COLORS = [
    "mediumturquoise","burlywood","royalblue","orange","midnightblue","firebrick",
    "darkkhaki","deepskyblue","indigo","limegreen","seagreen","rosybrown","tomato","sienna",
    "sandybrown","darkorange","darkgoldenrod","yellow","darkolivegreen","darkslategrey","slategrey",
    "darkslateblue","violet","hotpink","crimson"]
random.shuffle(COLORS)
COLORS =itertools.cycle(COLORS) 
LINESTYLES = itertools.cycle(["--","-", "--", "-.", ":"])
PLOTDIR = "/disk/CacheLib/examples/my_cache_1/plots";

# hr_lists: 3 * len(cache_sizes). 
def plot_hr_size(cache_sizes,hr_lists,labels,name=""): 
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        hr_list = [float(i) for i in hr_list]
        plt.plot(cache_sizes,hr_list,color=next(COLORS),linestyle=next(LINESTYLES),label=labels[i])

    legend = plt.legend(ncol=5, loc="upper right", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time") 
    plt.ylabel("Hit Ratio") 
    plt.savefig("{}/hrp-size-{}.pdf".format(PLOTDIR,name), bbox_inches="tight")
    plt.show() 
    plt.clf() 
    print("plot is saved to hrp-{}.pdf".format(name))



def run(tracepath,max_reqs,algo = "LRU",cache_size = "1GB"):
    if algo=="Lru": run_path = Lru_path;
    elif algo=="Lru2Q": run_path = Lru2Q_path;
    elif algo=="TinyLFU": run_path = TinyLFU_path;
    else: 
        print("unsupported algorithm ", algo);


    run_args = [run_path, tracepath,str(max_reqs),cache_size]

    p = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if p.returncode != 0: 
        logger.warning("cachesim may have crashed with segfault")

    stderr_str = p.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)

    stdout_str = p.stdout.decode("utf-8").split("\n");
    
    if len(stdout_str) < 3: 
        print(std_str)
        return

    line = stdout_str[-3]
    m = re.search(REGEX,line)

    if not m:
        print(line)
        return

    final_hr = m.group("hit_ratio")

    print(final_hr)
    return final_hr


if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--tracepath",type=str,required=True)
    p.add_argument("--cache_sizes",type=str,default="")

    p.add_argument("--algo",type=str,default="Lru")
    p.add_argument("--max_reqs",type=int,default=0)
    p.add_argument("--name",type=str,default="")

    ap = p.parse_args()  
    cache_sizes = CACHE_SIZES if (ap.cache_sizes=="") else ap.cache_sizes.split(",")

    # to allow parallelization. 

    hr_lists_for_algos = [[] for _ in range(len(ALGOS))]
    for (i,algo) in enumerate(ALGOS):
        for cache_size in cache_sizes:
            print("running",ap.tracepath,"with", algo,"and cache_size",cache_size) 
            final_hr = run(ap.tracepath,ap.max_reqs,algo=algo,cache_size = cache_size)
            hr_lists_for_algos[i].append(final_hr)

    plot_hr_size(cache_sizes,hr_lists_for_algos,ALGOS,name=ap.name)
