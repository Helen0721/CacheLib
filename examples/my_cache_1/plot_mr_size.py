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

Lru_path = "/disk/CacheLib-M24/examples/my_cache_1/build/my_cache_Lru"
Lru2Q_path = "/disk/CacheLib-M24/examples/my_cache_1/build/my_cache_Lru2Q"
TinyLFU_path = "/disk/CacheLib-M24/examples/my_cache_1/build/my_cache_TinyLFU"


ALGOS = ["Lru","Lru2Q","TinyLFU"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "", 
                            "MarginalHits", 
                            "HitsPerSlab"
                            ]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]
CACHE_SIZES_BYTES=[256000000,512000000,1000000000,2000000000,
                4000000000,8000000000,16000000000,32000000000,64000000000]

REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 
#COLORS=[
#        ("#9ebcda","#8856a7","#238b45"),
#        ("#b3cde3","#8c96c6","#88419d"),
#        ("#bae4bc","#7bccc4","#2b8cbe"),
#]

COLORS=['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]
COLORS =itertools.cycle(COLORS)

MARKERS=["o","x","d","s"]
MARKERS=itertools.cycle(MARKERS)

LINESTYLES =["-","-.", "-.", ":"]
LINESTYLES = itertools.cycle(LINESTYLES)

PLOTDIR = "/disk/CacheLib-M24/examples/my_cache_1/plots"


OUTPUTDIR = "/disk/CacheLib-M24/examples/my_cache_1/output/"

# hr_lists: 3 * len(cache_sizes). 
def plot_mr_size(cache_sizes,hr_lists,labels,name="",suffix=""): 
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    plot_fname = "{}/mrp-size-{}".format(PLOTDIR,name)
    
    plot_fname = (plot_fname + ".pdf") if (suffix=="") else (plot_fname+ "_" + suffix + ".pdf")

    pp = PdfPages(plot_fname)

    #log plot
    plt.figure()
    
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list] 
        plt.plot(cache_sizes,mr_list,
                color=next(COLORS),
                label=labels[i],
                marker=next(MARKERS),
                linestyle=next(LINESTYLES)
                )

    plt.title("log scale")
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lies ), 
                        loc="upper right", fontsize="6", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()

    pp.close()

    print("log plot saved to {}".format(plot_fname))

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
    p.add_argument("--name",type=str,required=True)
    
    p.add_argument("--cache_sizes",type=str,default="")
    p.add_argument("--rebalance_strategies",type=str,default="")
    p.add_argument("--algo",type=str,default="Lru")

    ap = p.parse_args()  
   
    # given a trace, x axis is the cache size. y axis is the miss ratio.  
    # we want [Lru, Lru2Q, TinyLFU] * [4 rebalancing strategy]

    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",")


    if (ap.rebalance_strategies==""):
        rebalance_strategies = REBALANCEING_STRATEGIES
    else:
        rebalance_strategies = ap.rebalance_strategies.split(",")


    hr_lists,labels = [],[]
    for (i,algo) in enumerate(ALGOS):
        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
            hr_lists.append([])
            labels.append(rebalance_strategy + "-" + algo)

            for cache_size in cache_sizes:     
                if (rebalance_strategy!=""):
                    output_file = OUTPUTDIR + ap.name + "_" + algo + \
                        "_" + cache_size + "_" + rebalance_strategy + ".txt"
                else:
                    output_file = OUTPUTDIR + ap.name + "_" + algo + \
                            "_" + cache_size + ".txt"
 
                print("parsing for",output_file) 

                final_hr = parse_for_size(output_file)
                hr_lists[-1].append(final_hr)
                

    print(hr_lists)

    plot_mr_size(cache_sizes,hr_lists,labels,name=ap.name,suffix="reb")
