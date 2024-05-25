import os
import sys
import itertools
from collections import defaultdict
from matplotlib.backends.backend_pdf import PdfPages
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
COLORS=['tab:green', 'tab:red', 'tab:blue']
MARKERS=["o","x","d","s"]
LINESTYLES =["-","-.", "-.", ":"]

PLOTDIR = "/disk/CacheLib/examples/my_cache_1/plots"

OUTPUTDIR = "/disk/CacheLib/examples/my_cache_1/output/"

def plot_hr_time(ts_lists,hr_lists,labels,cache_size="1GB",name=""): 
    num_lines = len(ts_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    pp = PdfPages("{}/mrp-time-{}-{}.pdf".format(PLOTDIR,name,cache_size))

    #linear scale

    plt.figure()
    for i in range(num_lines): 
        ts_list,hr_list = ts_lists[i],hr_lists[i] 
        ts_list = [float(i) for i in ts_list] 
        mr_list = [1-float(i) for i in hr_list]
        
        plt.plot(ts_list, mr_list,
                color=COLORS[i],
                label=labels[i],
                marker=MARKERS[i],
                linestyle=LINESTYLES[i])

    plt.title("linear scale")
    legend = plt.legend(ncol=num_lines, loc="upper right", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()

    pp.close()

    print("linear plot saved to mrp-time-{}-{}.pdf".format(name,cache_size))



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

    ts_list,hr_list = [],[]
    
    for (i,line) in enumerate(stdout_str):
        if i == len(stdout_str) - 2: break 
        
        m = re.search(REGEX,line) 

        if not m: continue

        ts_list.append(m.group("time")) 
        hr_list.append(m.group("hit_ratio"))
    
    #print(ts_list) 
    #print(hr_list)

    return ts_list, hr_list


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
    
    #print(ts_list) 
    #print(hr_list)

    return ts_list, hr_list


if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--tracepath",type=str,default="")
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--algo",type=str,default="")
    p.add_argument("--max_reqs",type=int,default=0)
    p.add_argument("--cache_size",type=str,default="1GB")

    ap = p.parse_args()

    algos = ALGOS if (ap.algo=="") else [ap.algo]
            
    #for algo in algos:
        #print("running",ap.tracepath,"with", algo,"and",ap.cache_size) 
        #ts_list,hr_list = run(ap.tracepath,ap.max_reqs,algo=algo,cache_size = ap.cache_size) 
    
    cache_sizes = [ap.cache_size] if ap.cache_size!="all" else CACHE_SIZES

    for cache_size in cache_sizes:
        ts_lists_for_algos,hr_lists_for_algos,labels = [],[],[] 

        for (i,algo) in enumerate(ALGOS):
            #for cache_size in cache_sizes: 
            output_file = OUTPUTDIR + ap.name + "_" + algo + "_" + cache_size + ".txt"
            
            print("parsing for",output_file) 

            ts_list,hr_list = parse_for_time(output_file)
   
            ts_lists_for_algos.append(ts_list) 
            hr_lists_for_algos.append(hr_list) 
                
            labels.append(algo)

        plot_hr_time(ts_lists_for_algos,hr_lists_for_algos,labels,cache_size=cache_size,name=ap.name)
