import os
import glob
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
import logging



CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]
ALGOS = ["Lru","Lru2Q","TinyLFU"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "FreeMem", 
                            "MarginalHits", 
                            "HitsPerSlab",
                            "default"
                            ]

PWD = os.getcwd()
REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 


colors=['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]

markers=["o","x","d","s"]
linestyles =["-","-.", "-.", ":"]

def plot(plot_dir,plot_name,plot_title,hr_lists,cache_sizes,labels):
    
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    plot_fname = os.path.join(plot_dir,"reb-size-"+plot_name+"-"+plot_title+".pdf")

    pp = PdfPages(plot_fname)
    #log plot
    plt.figure()
    
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list] 
        print(mr_list)
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
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()
    pp.close()

    print("log plot saved to {}".format(plot_fname))


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



def handle():
    hr_lists,labels = [],[]
    for (i,algo) in enumerate(algos):
        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
            
            if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

            hr_lists.append([])
            labels.append(rebalance_strategy + "-" + algo)



def handle_best():

    algo_sep_s = "Difference between best and worst in miss ratio"
    mr_s = "'Final Miss Ratio': "

    labels = []
    
    for (i,rebalance_strategy) in enumerate(rebalance_strategies):
        print("parsing for",os.path.join(ap.output_folder,rebalance_strategy+"_best.txt"))
        best_summary_f = open(os.path.join(ap.output_folder,rebalance_strategy+"_best.txt"),"r")
        best_summary_L = best_summary_f.read().split("-"*100)
        
        assert len(best_summary_L) >= len(cache_sizes)

        labels_for_cs = []
        for (j, cache_size) in enumerate(cache_sizes):
            best_summary_for_cs_s = best_summary_L[j].split("\n\n\n\n")[1]
            best_summary_for_cs_L = best_summary_for_cs_s.split(algo_sep_s)
            
            for L in best_summary_for_cs_L: print(L)


            for (k,algo) in enumerate(algos):
                best_summary_for_cs = best_summary_for_cs_L[k].split("\n\n")[0].split(mr_s)
                mr = float(best_summary_for_cs[-1][:-1])
                print(mr)



if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--plot_type",type=str,required=True)
    
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
        algos = ap.algos.split(",")

    if ap.plot_type == "bestReb":
        handle_best()
    

