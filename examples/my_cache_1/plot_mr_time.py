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
ALLOC_CLASSES = [72, 96, 120, 152, 192, 240, 304, 384, 480, 600, 752, 944, 
        1184, 1480, 1856, 2320, 2904, 3632, 4544, 5680, 7104, 8880, 11104, 
        13880, 17352, 21696, 27120, 33904, 42384, 52984, 66232, 82792, 103496, 
        129376, 161720, 202152, 252696, 315872, 394840, 493552, 
        616944, 771184, 963984, 1204984, 1506232, 1882792, 4194304]


REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 

REGEX_CacheStats = "class alloc size: (?P<class_alloc_size>\d+), total_alloc_attemtps: (?P<total_alloc_attemtps>\d+), total_evict_attempts: (?P<total_evict_attempts>\d+), total_numHits: (?P<total_numHits>\d+), total_allocFailures: (?P<total_allocFailures>\d+)."

colors =['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]

markers=["o","x","d","s"]

linestyles = ["-","-.", "-.", ":"]


def plot_allocAttempts_time(ts_lists,
                    alloc_attempts,
                    alloc_sizes_for_plot,
                    mod,
                    cache_size,
                    plot_folder,
                    plot_name,
                    plot_title):

    # Took every 10000000 requests
    times_idx = [i for i in range(len(ts_lists)) if i % mod == 0 and i > 0]
    ts_lists_for_plot = [ts_lists[i] for i in times_idx]
    x = np.arange(len(ts_lists_for_plot))
    alloc_attempts_for_plot = [alloc_attempts[i] for i in times_idx]
    
    # group alloc attempts by allocation classes
    alloc_attempts_by_category = [[] for _ in range(len(alloc_sizes_for_plot))]
    for i in range(len(alloc_sizes_for_plot)):
        for alloc_attempts_for_time in alloc_attempts_for_plot:
            alloc_attempts_by_category[i].append(alloc_attempts_for_time[i])
    
    #print(ts_lists_for_plot)
    #print(alloc_attempts_for_plot)
    # checking we are just transposing the list
    for (i,alloc_attempts_for_category) in enumerate(alloc_attempts_by_category):
        assert(len(alloc_attempts_for_category) == len(ts_lists_for_plot))
        for (j,alloc_attempt) in enumerate(alloc_attempts_for_category):
            assert(alloc_attempt == alloc_attempts_for_plot[j][i])

    
    # filter out allocation classes that have zero allocations
    alloc_class_idx = [i for i in range(len(alloc_sizes_for_plot)) if sum(alloc_attempts_by_category[i]) > 0]
    alloc_attempts_by_category = [alloc_attempts_by_category[i] for i in alloc_class_idx]
    alloc_sizes_for_plot = [alloc_sizes_for_plot[i] for i in alloc_class_idx]
    num_categories = len(alloc_sizes_for_plot)

    plot_fname = os.path.join(plot_folder,"{}-AllocAttempts.pdf".format(plot_name)) 
    pp = PdfPages(plot_fname)

    #linear scale 
    fig, ax = plt.subplots(figsize=(50,40))

    COLORS = plt.cm.tab20(np.linspace(0, 1, num_categories+1))
    
    for i in range(num_categories):  
        alloc_attempts_for_category = alloc_attempts_by_category[i] 
          
        print("alloc_attempts_for_cateogry:",alloc_attempts_for_category)

        if i == 0:
            ax.bar(x, 
                    alloc_attempts_for_category, 
                    label = str(alloc_sizes_for_plot[i]),
                    color=COLORS[i])
            bottom_for_category = np.array(alloc_attempts_for_category)
        else:
            ax.bar(x, 
                    alloc_attempts_for_category, 
                    bottom=bottom_for_category,
                    label = str(alloc_sizes_for_plot[i]),
                    color=COLORS[i])
            bottom_for_category += np.array(alloc_attempts_for_category)             
        print("bottom_for_category:", bottom_for_category)

      
        
    ax.set_xlabel("Time",fontsize=35)
    ax.set_xticks(x)
    ax.set_xticklabels(ts_lists_for_plot)
    ax.tick_params(axis='x', which='major', labelsize=35)

    #ax.set_yscale('linear')
    ax.set_ylabel("AllocAttempts",fontsize=35)
    ax.tick_params(axis='y', which='major', labelsize=35)   
    #secax = ax.secondary_yaxis('right', functions=(custom_scale, inverse_custom_scale))
    #secax.set_yticks(ticks)
    #secax.set_yticklabels(labels)

    ax.set_title(plot_title + "-" + cache_size,fontsize=18)

    legend = ax.legend(fontsize="35", bbox_to_anchor=(0, 1), 
            ncol=5,loc='upper left')
    
    plt.tight_layout(pad=2.0)

    pp.savefig(fig)
    plt.close(fig)
    pp.close()

    print("alloc_attempts plot saved to {}".format(plot_fname))


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

            alloc_attempts_list_for_time.append(int(total_alloc_attemtps))
            alloc_sizes.append(int(class_alloc_size))

        ts_list.append(int(time))
        alloc_attempts_list.append(alloc_attempts_list_for_time)
        
        i += 1

    return ts_list, alloc_sizes, alloc_attempts_list

def handle_mr():
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

                            
                print("parsing for",output_file) 

                ts_list,hr_list = parse_for_time(output_file) 
               
                print(ts_list)

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
        



def handle_CacheStats():
    
    if ap.name=="w06":
        mod = 5
    #(?P<hit_ratio>\d+.\d+)
    elif (re.search(r"w(?P<CloudPhysics_trace>\d+)",ap.name)): 
        mod = 1
    else:
        mod = 10

    for cache_size in cache_sizes:
        ts_lists_for_cs,hr_lists_for_cs,alloc_sizes_for_cs,alloc_attempts_list_for_cs,labels = [],[],[],[],[] 

        for (i,algo) in enumerate(algos):
            for (j,rebalance_strategy) in enumerate(rebalance_strategies):

                if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue
                
                CacheStats_file = os.path.join(ap.output_folder,rebalance_strategy,
                            "CacheStats_{}_{}_{}_default".format(algo,cache_size,rebalance_strategy)
                            )

                print("parsing for",CacheStats_file)
                ts_list, alloc_sizes, alloc_attempts_list = parse_for_time_CacheStats(CacheStats_file)

                plot_name_for_allocAttempts = "{}-{}-{}-{}".format(ap.name,cache_size,algo,rebalance_strategy)
                plot_title_for_allocAttempts = "{}-{}-{}".format(cache_size,algo,rebalance_strategy)
                
                plot_allocAttempts_time(ts_list,
                        alloc_attempts_list,
                        alloc_sizes,
                        mod,
                        cache_size,
                        plot_folder=ap.plot_folder,
                        plot_name=plot_name_for_allocAttempts,
                        plot_title=plot_title_for_allocAttempts
                     )
                

def validate_CacheStats():
    cache_size = cache_sizes[0]
    algo = algos[0]
    rebalance_strategy = rebalance_strategies[0]


    CacheStats_file = os.path.join(ap.output_folder,rebalance_strategy,
                            "CacheStats_{}_{}_{}_default".format(algo,cache_size,rebalance_strategy)
                            )

    print("parsing for",CacheStats_file)
    ts_list, alloc_sizes, alloc_attempts_list = parse_for_time_CacheStats(CacheStats_file)
    
    print(alloc_sizes)
    print(alloc_attempts_list[0])

    sizeToAllocAttempts = {size: alloc_attempts_list[0][i] for (i,size) in enumerate(alloc_sizes)}

    with open(ap.ref_tracePrint,"r") as f:
        ref_tracePrint = f.read().split("\n")

    ref_all_sizes = []
    for (i,line) in enumerate(ref_tracePrint):
        if i < 2: continue
        try: 
            size = line.split(",")[2]
            ref_all_sizes.append(int(size)+32)  # memory overhead
        except:
            print(line)
            continue

    ref_sizeToAllocAttempts = {size:0 for size in alloc_sizes}
    for obj_size in ref_all_sizes:
        for curr in alloc_sizes+[999999999999999999]:
            if curr > obj_size:
                ref_sizeToAllocAttempts[curr] += 1
                break
    
    ref_totalObjs = len(ref_all_sizes)
    totalAllocAttempts = sum(alloc_attempts_list[0])
    
    for size in alloc_sizes:
        print("size: {}. ref cnt: {}, my cnt: {}".format(size,
            ref_sizeToAllocAttempts[size],sizeToAllocAttempts[size]))
        
    print("ref_totalObjs: {}, totalAllocAttempts: {}".format(
        ref_totalObjs,totalAllocAttempts))


    print("max obj size:",max(ref_all_sizes),"min obj size:",min(ref_all_sizes))


def handle_objSizeDist():
    with open(ap.ref_tracePrint,"r") as f:
        ref_tracePrint = f.read().split("\n")

    ref_all_sizes = []
    for (i,line) in enumerate(ref_tracePrint):
        if i < 2: continue
        try: 
            size = line.split(",")[2]
            ref_all_sizes.append(int(size))
        except:
            print(line)
            continue
   
    
    #classToId = {c:i for (i,c) in enumerate(ALLOC_CLASSES)}
    
    #objSizeCnts = []

    #for obj_size in ref_all_sizes:
    #    prev = alloc_sizes[0]
    #    for curr in alloc_sizes+[999999999999999999]:
    #        if curr > obj_size:
    #            ref_sizeToAllocAttempts[prev] += 1
    #            break
    #        prev = curr






if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--name",type=str,required=True) 
    p.add_argument("--type",type=str,required=True)

    p.add_argument("--cache_sizes",type=str,default="all")
    p.add_argument("--algos",type=str,default="all")
    p.add_argument("--organized",type=str,default="no")
    p.add_argument("--rebalance_strategies",type=str,default="all")
    p.add_argument("--ref_tracePrint",type=str,default=None)

    ap = p.parse_args()

    algos = ALGOS if (ap.algos=="all") else ap.algos.split(",")
                 
    cache_sizes = ap.cache_sizes.split(",") if ap.cache_sizes!="all" else CACHE_SIZES

    rebalance_strategies = ap.rebalance_strategies.split(",") if \
        (ap.rebalance_strategies!="all") else REBALANCEING_STRATEGIES 
    
    if ap.type=="CacheStats":
        handle_CacheStats()
    elif ap.type=="mr":
        hanld_mr()
    elif ap.type=="validate_CacheStats":
        validate_CacheStats()
    elif ap.type=="objSizeDist":
        handle_objSizeDist()
    else:
        print("operation",ap.type,"not supported")
    
