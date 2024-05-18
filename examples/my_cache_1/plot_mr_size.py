import os
import sys
import itertools
from collections import defaultdict
import re
import numpy as np
import random
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
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
CACHE_SIZES_BYTES=[256000000,512000000,1000000000,2000000000,
                4000000000,8000000000,16000000000,32000000000,64000000000]

REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 
#COLORS=[
#        ("#9ebcda","#8856a7","#238b45"),
#        ("#b3cde3","#8c96c6","#88419d"),
#        ("#bae4bc","#7bccc4","#2b8cbe"),
#]

COLORS=["#bae4bc","#7bccc4","#2b8cbe"]
#random.shuffle(COLORS)
#COLORS =itertools.cycle(COLORS)

MARKERS=["o","x","d","s"]
#random.shuffle(MARKERS)
#MARKERS=itertools.cycle(MARKERS)

LINESTYLES =["-","-.", "-.", ":"]
#random.shuffle(LINESTYLES)
#LINESTYLES = itertools.cycle(LINESTYLES)

PLOTDIR = "/disk/CacheLib/examples/my_cache_1/plots";

# hr_lists: 3 * len(cache_sizes). 
def plot_mr_size(cache_sizes,cache_sizes_bytes,hr_lists,labels,name=""): 
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    pp = PdfPages("{}/mrp-size-{}.pdf".format(PLOTDIR,name))

    #linear plot
    plt.figure()
    
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list] 
        plt.plot(cache_sizes,mr_list,
                color=colors[i],
                label=labels[i],
                market=MARKERS[i],
                linestyle=LINESTYLES[i])

    plt.title("linear scale")
    legend = plt.legend(ncol=num_lines, loc="upper right", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()

    #log plot

    plt.figure()
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list]
        plt.plot(cache_sizes_bytes,mr_list,
                color=colors[i],
                label=labels[i],
                market=MARKERS[i],
                linestyle=LINESTYLES[i])        
        plt.xscale("log")

    plt.title("log scale")
    legend = plt.legend(ncol=num_lines, loc="upper right", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()

    pp.close()

    print("linear and log plots are saved to mrp-size-{}.pdf".format(name))


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
    
    print(stdout_str[-2])

    final_hr = m.group("hit_ratio")

    print("miss ratio:",1-float(final_hr))
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
    
    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
        cache_sizes_bytes = CACHE_SIZES_BYTES
    else:
        cache_sizes = ap.cache_sizes.split(",")
        cache_sizes_bytes = [CACHE_SIZES_BYTES[CACHE_SIZES.index(s)] for s in cache_sizes] 

    # to allow parallelization. 

    hr_lists_for_algos = [[] for _ in range(len(ALGOS))]
    for (i,algo) in enumerate(ALGOS):
        for cache_size in cache_sizes:
            print("running",ap.tracepath,"with", algo,"and cache_size",cache_size) 
            final_hr = run(ap.tracepath,ap.max_reqs,algo=algo,cache_size = cache_size)
            hr_lists_for_algos[i].append(final_hr)

    plot_mr_size(cache_sizes,cache_sizes_bytes,hr_lists_for_algos,ALGOS,name=ap.name)
