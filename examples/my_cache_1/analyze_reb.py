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

ALGOS = ["Lru","Lru2Q","TinyLFU"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "FreeMem", 
                            "MarginalHits", 
                            "HitsPerSlab",
                            "default"
                            ]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]


START_REB_s = "Trying Rebalancing"

FAIL_REASONS = {
        "Universal": ["has #free alocs above threshold","Not all mem. in the pool is alloc. to some slab"],
        "LruTailAge": ["vPTA < rTA", "improv. < minTailAgeDifference", "improv. < diffRatio * vPTA"],
        "FreeMem" : [],
        }

ABBRV = {
    FAIL_REASONS["Universal"][0]: "FreeAllocAbvThrsld",
    FAIL_REASONS["Universal"][1]: "FreeMemNotAlloc"
    }


SUC_s = "hold off started"

def collect_cnts(file,reb):

    with open(file,"r") as f:
        stdout_str = f.read()


    res = {"total_attempts": stdout_str.count(START_REB_s),
            "suc_attempts": stdout_str.count(SUC_s)
          }
    
    for i,r in enumerate(FAIL_REASONS["Universal"]):
        res[ABBRV[r]] = stdout_str.count(r)
    
    for i,r in enumerate(FAIL_REASONS[reb]):
        res[r] = stdout_str.count(r)

    return res



if __name__=="__main__":
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    #p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    
    p.add_argument("--cache_sizes",type=str,default="")
    p.add_argument("--rebalance_strategies",type=str,default="all")
    p.add_argument("--algo",type=str,default="all")

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


    if ap.algo=="all":
        algos = ALGOS
    else:
        algos = [ap.algo]


    for (i,algo) in enumerate(algos):
        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
            if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

            for cache_size in cache_sizes:     
                output_file =os.path.join(ap.output_folder,
                        ap.name + "_" + algo + "_" +cache_size+"_"+rebalance_strategy+".txt")

                cnt_res = collect_cnts(output_file,rebalance_strategy)

                print(cnt_res)
