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

COLORS=['tab:green', 'tab:red', 'tab:blue']
#random.shuffle(COLORS)
#COLORS =itertools.cycle(COLORS)

MARKERS=["o","x","d","s"]
#random.shuffle(MARKERS)
#MARKERS=itertools.cycle(MARKERS)

LINESTYLES =["-","-.", "-.", ":"]
#random.shuffle(LINESTYLES)
#LINESTYLES = itertools.cycle(LINESTYLES)

PLOTDIR = "/disk/CacheLib/examples/my_cache_1/plots"


OUTPUTDIR = "/disk/CacheLib/examples/my_cache_1/output/"

# hr_lists: 3 * len(cache_sizes). 
def plot_mr_size(cache_sizes,hr_lists,labels,name=""): 
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    pp = PdfPages("{}/mrp-size-{}.pdf".format(PLOTDIR,name))

    #log plot
    plt.figure()
    
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list] 
        plt.plot(cache_sizes,mr_list,
                color=COLORS[i],
                label=labels[i],
                marker=MARKERS[i],
                linestyle=LINESTYLES[i])

    plt.title("log scale")
    legend = plt.legend(ncol=num_lines, loc="upper right", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()

    pp.close()

    print("log plot saved to mrp-size-{}.pdf".format(name))

def parse_for_time(file):
    stdout_str = []

    with open(file,"r") as f:
        stdout_str = f.read().split("\n")
    
    ts_list,hr_list = [],[]
    
    for (i,line) in enumerate(stdout_str):
        if i == len(stdout_str) - 2: break 
        
        m = re.search(REGEX,line) 

        if not m: continue

        ts_list.append(m.group("time")) 
        hr_list.append(m.group("hit_ratio"))
    
    print(ts_list) 
    print(hr_list)

    return ts_list, hr_list





def parse_for_size(file):
    
    stdout_str = []
    with open(file,"r") as f:
        stdout_str = f.read().split("\n")
    
    line = stdout_str[-3]
    m = re.search(REGEX,line)

    if not m:
        print("incorrect output file format")
        print(line)
        return -1
    
    final_hr = m.group("hit_ratio")

    print("miss ratio:",1-float(final_hr))
    return final_hr


if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    #p.add_argument("--tracepath",type=str,required=True)
    p.add_argument("--cache_sizes",type=str,default="")

    p.add_argument("--algo",type=str,default="Lru")
    p.add_argument("--max_reqs",type=int,default=0)
    p.add_argument("--name",type=str,default="")

    ap = p.parse_args()  
    
    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",")

    hr_lists_for_algos = [[] for _ in range(len(ALGOS))]
    for (i,algo) in enumerate(ALGOS):
        for cache_size in cache_sizes: 
            output_file = OUTPUTDIR + ap.name + "_" + algo + "_" + cache_size + ".txt"
            
            print("parsing for",output_file) 

            final_hr = parse_for_size(output_file)
            hr_lists_for_algos[i].append(final_hr)

    plot_mr_size(cache_sizes,hr_lists_for_algos,ALGOS,name=ap.name)
