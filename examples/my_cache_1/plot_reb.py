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
                            ""
                            ]
PWD = os.getcwd()
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


if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_dirs",type=str,required=True)
    p.add_argument("--names",type=str,required=True)
    p.add_argument("--algo",type=str,required=True)
    p.add_argument("--reb",type=str,required=True)
    p.add_argument("--plot_dir",type=str,required=True)
    p.add_argument("--plot_name",type=str,required=True)

    p.add_argument("--cache_sizes",type=str,default="all")

    ap = p.parse_args()  

    plot_dir = os.path.join(PWD,ap.plot_dir)
    output_dirs = ap.output_dirs.split(";")
    names = ap.names.split(";")
    names = [names_.split(",") for names_ in names]
    cache_sizes = CACHE_SIZES if (ap.cache_sizes=="all") else ap.cache_sizes.split(",") 
 
    hrs = []
    labels = []

    for (i,output_dir) in enumerate(output_dirs):
        for name in names[i]:
            output_file_prefix = os.path.join(PWD,output_dir,name+"_"+ap.algo+"_")

            output_files = glob.glob(f"{output_file_prefix}*")  
            
            hr_for_file = []

            for output_file in output_files:
                if output_file[:-4].endswith(ap.reb):
                    print(output_file)
                    hr = parse_for_size(output_file)
                    hr_for_file.append(hr)

                else if ap.reb=="none" and 

            hrs.append(hr_for_file)
            labels.append(name)

    print(hrs)

    plot_title = ap.reb
    plot(ap.plot_dir,ap.plot_name,plot_title,hrs,cache_sizes,labels)

    

