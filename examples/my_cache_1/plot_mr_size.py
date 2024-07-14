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

ALGOS = ["Lru","Lru2Q","TinyLFU","Sieve"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "FreeMem", 
                            "MarginalHits", 
                            "HitsPerSlab",
                            "default",
                            ]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]
CACHE_SIZES_BYTES=[256000000,512000000,1000000000,2000000000,
                4000000000,8000000000,16000000000,32000000000,64000000000]

REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 


COLORS=['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]
COLORS =itertools.cycle(COLORS)

MARKERS=["o","x","d","s"]
MARKERS=itertools.cycle(MARKERS)

LINESTYLES =["-","-.", "-.", ":"]
LINESTYLES = itertools.cycle(LINESTYLES)

# hr_lists: 3 * len(cache_sizes). 
def plot_mr_size(cache_sizes,hr_lists,labels,plot_folder,plot_name,plot_title,suffix=""): 
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    plot_fname = os.path.join(plot_folder,"mrp-size-{}".format(plot_name))
    
    plot_fname = (plot_fname + ".pdf") if (suffix=="") \
                else (plot_fname+ "_" + suffix + ".pdf")

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

    plt.title(plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="6", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size")
    if len(cache_sizes) > len(CACHE_SIZES): plt.xticks(fontsize=6)
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()

    pp.close()

    print("log plot saved to {}".format(plot_fname))

def parse_for_size(file):
    
    stdout_str = []
    with open(file,"r") as f:
        stdout_str = f.read().split("\n")
    
    hr_list = []
    
    for (i,line) in enumerate(stdout_str):
        if i == len(stdout_str) - 2: break 
        
        m = re.search(REGEX,line) 

        if not m: continue

        hr_list.append(m.group("hit_ratio"))

    final_hr = hr_list[-1]

    print("miss ratio:",1-float(final_hr))
    return final_hr


def handle_mr():
    for (i,algo) in enumerate(algos):
        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
            
            if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

            hr_lists.append([])
            labels.append(rebalance_strategy + "-" + algo)

            for cache_size in cache_sizes:
                if json_RES:
                    res_ = json_RES[cache_size][rebalance_strategy][algo]["best_result"]
                    for fname,res in res_.items():
                        final_hr = 1-res["Final Miss Ratio"]
                else:

                    if ap.organized=="yes":
                        output_file =os.path.join(ap.output_folder,rebalance_strategy,
                            "{}_{}_{}_{}_default".format(ap.name,algo,cache_size,rebalance_strategy)
                            )
                        if not os.path.isfile(output_file):
                            if rebalance_strategy=="MarginalHits":
                                output_file =os.path.join(ap.output_folder,rebalance_strategy,
                                    "{}_{}_{}_{}_1,0.3,1,1".format(ap.name,algo,cache_size,rebalance_strategy)
                                    )
                            if not os.path.isfile(output_file): continue

                    else: 
                        output_file =os.path.join(ap.output_folder,
                            "{}_{}_{}_{}.txt".format(ap.name,algo,cache_size,rebalance_strategy)
                            )

                    print("parsing for",output_file) 

                    final_hr = parse_for_size(output_file)
                
                hr_lists[-1].append(final_hr)
                

    print(hr_lists)

    name = ap.name + "-" + ap.algo + "-" + ap.rebalance_strategies
    title = ap.algo + "-" + ap.rebalance_strategies

    plot_mr_size(cache_sizes,hr_lists,labels,plot_folder=ap.plot_folder,plot_name=name,plot_title=title)




def handle_uniform():

    for (i,algo) in enumerate(algos):
        for (j,reb) in enumerate(rebalance_strategies):
            if reb == "MarginalHits" and algo!="Lru2Q": continue

            hr_lists.append([])
            labels.append(algo + "-" + reb)

            for cache_size in cache_sizes:
                # ex: metakvt1_TinyLFU_4GB_default_default_uniform
                output_file = os.path.join(ap.output_folder,reb,
                        "{}_{}_{}_{}_default_uniform".format(ap.name,algo,cache_size,reb))
                if not os.path.isfile(output_file):
                    print("{} is not a file".format(output_file))
                    exit(1)

                final_hr = parse_for_size(output_file)
                
                hr_lists[-1].append(final_hr)
        
    print(hr_lists)
    name = ap.name + "-" + ap.algos + "-" + ap.rebalance_strategies + "-uniform"     
    title = ap.algos + "-" + ap.rebalance_strategies + "-uniform" 
    plot_mr_size(cache_sizes,hr_lists,labels,plot_folder=ap.plot_folder,plot_name=name,plot_title=title)


def handle_stopReb():
    hr_lists = []

    for (i,algo) in enumerate(algos):
        for (j,reb) in enumerate(rebalance_strategies):
            if reb == "MarginalHits" and algo!="Lru2Q": continue

            hr_lists.append([])    # hr_lists[-2] is for hr 
            hr_lists.append([])     # hr_lists[-1] is for hr_stopReb
            labels.append(algo + "-" + reb)
            labels.append(algo + "-" + reb + "-stopReb" )

            for cache_size in cache_sizes:
                output_file = os.path.join(ap.output_folder,reb,
                        "{}_{}_{}_{}_default".format(ap.name,algo,cache_size,reb))
             
                final_hr = parse_for_size(output_file)
                hr_lists[-2].append(final_hr)
                
                output_file_stopReb = os.path.join(ap.output_folder,reb,
                        "{}_{}_{}_{}_default_stopReb".format(ap.name,algo,cache_size,reb))

                final_hr_stopReb = parse_for_size(output_file_stopReb)

                hr_lists[-1].append(final_hr_stopReb)
 
    name = ap.name + "-" + ap.algos + "-" + ap.rebalance_strategies + "-" + ap.cache_sizes + "-stopReb"     
    title = ap.algos + "-" + ap.rebalance_strategies + "-stopReb" 
    
    plot_mr_size(cache_sizes,hr_lists,labels,plot_folder=ap.plot_folder,plot_name=name,plot_title=title)



if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--type",type=str,required=True)
    
    p.add_argument("--organized",type=str,default=None)
    p.add_argument("--json_file",type=str,default=None)    
    p.add_argument("--cache_sizes",type=str,default="")
    p.add_argument("--rebalance_strategies",type=str,default="all")
    p.add_argument("--algos",type=str,default="all")

    ap = p.parse_args()  
   
    # given a trace, x axis is the cache size. y axis is the miss ratio.  
    # we want [Lru, Lru2Q, TinyLFU] * [4 rebalancing strategy]

    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",")


    if (ap.rebalance_strategies=="all"):
        rebalance_strategies = REBALANCEING_STRATEGIES
    else:
        rebalance_strategies = ap.rebalance_strategies.split(",")


    if ap.algos=="all":
        algos = ALGOS
    else:
        algos = ap.algos.split("\n")

    json_RES = None
    if ap.json_file!=None:
        import json
        with open(ap.json_file,"r") as json_f:
            json_RES = json.load(json_f)

    hr_lists,labels = [],[]

    if ap.type == "uniform":
        handle_uniform()
    elif ap.type == "stopReb":
        handle_stopReb()
