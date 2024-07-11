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
import json

ALGOS = ["Lru","Lru2Q","TinyLFU"]
CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "FreeMem", 
                            "MarginalHits", 
                            "HitsPerSlab",
                            "default"
                            ]

REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 

REGEX_CacheStats = "class alloc size: (?P<class_alloc_size>\d+), total_alloc_attemtps: (?P<total_alloc_attemtps>\d+), total_evict_attempts: (?P<total_evict_attempts>\d+), total_numHits: (?P<total_numHits>\d+), total_allocFailures: (?P<total_allocFailures>\d+)."

colors =['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]

markers=["o","x","d","s"]

linestyles = ["-","-.", "-.", ":"]

def plot_hr_time(ts_lists,
                 hr_lists,
                 labels,
                 cache_size,
                 plot_folder,
                 plot_name,
                 plot_title,
                 suffix=""): 
    COLORS =itertools.cycle(colors)
    MARKERS=itertools.cycle(markers)
    LINESTYLES = itertools.cycle(linestyles)

    num_lines = len(ts_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return
    
    plot_fname = os.path.join(plot_folder,"mrp-time-{}-{}".format(plot_name,cache_size))
 
    plot_fname = (plot_fname + ".pdf") if (suffix=="") \
                else (plot_fname+ "_" + suffix + ".pdf")

    pp = PdfPages(plot_fname)

    #linear scale

    plt.figure()
    for i in range(num_lines): 
        ts_list,hr_list = ts_lists[i],hr_lists[i] 
        ts_list = [float(i) for i in ts_list] 
        mr_list = [1-float(i) for i in hr_list]
        
        plt.plot(ts_list, mr_list,
                color=next(COLORS),
                label=labels[i],
                marker=next(MARKERS),
                linestyle=next(LINESTYLES)
                )

    plt.title(plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="10", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time",fontsize=8) 
    plt.xticks(fontsize=10)
    plt.ylabel("Miss Ratio",fontsize=8)
    plt.yticks(fontsize=10)
    plt.tight_layout(pad=1.0)
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
    
    #print(ts_list) 
    #print(hr_list)

    return ts_list, hr_list


def parse_for_time_CacheStats(file):
    stdout_str = []
    
    with open(file,"r") as f:
        stdout_str = f.read().split("\n\n\n")
    
    ts_list = []
    alloc_attempts_list = [] 

    i = 0
    for section in stdout_str:
        lines = section.split("\n")
        
        if "time" not in lines[0]: continue 
        time = int(lines[0].split(": ")[1])

        alloc_attempts_list_for_time = []
        alloc_sizes = []
        
        for line in lines:
            m = re.search(REGEX_CacheStats,line)
            
            if not m: continue

            class_alloc_size = m.group("class_alloc_size")
            total_alloc_attemtps = m.group("total_alloc_attemtps")

            alloc_attempts_list_for_time.append(total_alloc_attemtps)
            alloc_sizes.append(class_alloc_size)

        ts_list.append(time)
        alloc_attempts_list.append(alloc_attempts_list_for_time)
        
        i += 1

    return ts_list, alloc_sizes, alloc_attempts_list


if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--cache_sizes",type=str,required=True)

    p.add_argument("--algo",type=str,default="all")
    p.add_argument("--organized",type=str,default="no")
    p.add_argument("--rebalance_strategies",type=str,default="all")

    ap = p.parse_args()

    algos = ALGOS if (ap.algo=="all") else [ap.algo]
                 
    cache_sizes = ap.cache_sizes.split(",") if ap.cache_sizes!="all" else CACHE_SIZES

    rebalance_strategies = ap.rebalance_strategies.split(",") if \
        (ap.rebalance_strategies!="all") else REBALANCEING_STRATEGIES 

    for cache_size in cache_sizes:
        ts_lists_for_cs,hr_lists_for_cs,labels = [],[],[] 

        for (i,algo) in enumerate(algos):
            for (j,rebalance_strategy) in enumerate(rebalance_strategies):

                if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

                if ap.organized=="no": 
                    output_file =os.path.join(ap.output_folder,ap.name + "_" + algo + "_" +cache_size)
                    if (rebalance_strategy!=""):
                        output_file = output_file + "_" + rebalance_strategy +".txt"
                    else:
                        output_file = output_file + ".txt"
                else:
                    output_file = os.path.join(ap.output_folder,rebalance_strategy,
                            "{}_{}_{}_{}_default".format(ap.name,algo,cache_size,rebalance_strategy)
                            )
                    
                    CacheStats_file = os.path.join(ap.output_folder,rebalance_strategy,
                            "CacheStats_{}_{}_{}_default".format(algo,cache_size,rebalance_strategy)
                            )


                            
                #print("parsing for",output_file) 

                #ts_list,hr_list = parse_for_time(output_file)

                print("parsing for",CacheStats_file)
                ts_list, alloc_sizes, alloc_attempts_list = parse_for_time_CacheStats(CacheStats_file)
               
                print(ts_list)
                print(alloc_attempts_list)
                print(alloc_sizes)
                exit(0)

                ts_lists_for_cs.append(ts_list) 
                hr_lists_for_cs.append(hr_list) 
                labels.append(rebalance_strategy + "-" + algo)

        
        plot_name = ap.name + "-" + ap.algo + "-" + ap.rebalance_strategies
        plot_title = ap.algo + "-" + ap.rebalance_strategies + "-" + cache_size

        plot_hr_time(ts_lists_for_cs,
                     hr_lists_for_cs,
                     labels,
                     cache_size,
                     plot_folder=ap.plot_folder,
                     plot_name=plot_name,
                     plot_title=plot_title
                     )
