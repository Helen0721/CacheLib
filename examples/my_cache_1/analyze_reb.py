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
        "Universal": ["has #free alocs above threshold",
                      "Not all mem. in the pool is alloc. to some slab"],
        "LruTailAge": ["vPTA < rTA", 
                       "improv. < minTailAgeDifference", 
                       "improv. < diffRatio * vPTA"],
        "FreeMem" : ["all classes are evicting",
                     "Total free mem.", #smaller than threshold",
                     ] ,
        "MarginalHits": ["invalid max or main ranks"],
        "HitsPerSlab": ["invalid class id", 
                        "rDHpS < vPDHpS", 
                        "improv.< minDiff",
                        "improv.< diffRatio * vPDHpS" ]
        }

STRTGY_TRIGGERED_s = "hold off started."
MarginalHits_triggered_s = FreeMem_triggered_s = "picked."
FAILALLOC_TRIGGERED_s = "hold off started w/o triggering strategy specific pickVandRImp"

ABBRV = {
    FAIL_REASONS["Universal"][0]: "FreeAllocAbvThrsld",
    FAIL_REASONS["Universal"][1]: "FreeMemNotAlloc",
    FAIL_REASONS["FreeMem"][1]: "Total free mem. smaller than thrshld",
    STRTGY_TRIGGERED_s: "StrtgyTriggered",
    MarginalHits_triggered_s: " StrtgyTriggered",
    FreeMem_triggered_s: " StrtgyTriggered",
    FAILALLOC_TRIGGERED_s: "TriggeredByFailAlloc",
    }
MISS_RATIO_s = "Final Miss Ratio"

def find_best_and_worst(results):
    best_i,best_mr = -1,1.0
    worst_i,worst_mr = -1,0.0

    for (i,r) in enumerate(results):
        mr_s = r.split(MISS_RATIO_s)[1][3:-1]
        mr = float(mr_s)

        if mr < best_mr:
            best_i = i
            best_mr = mr

        if mr > worst_mr:
            worst_i = i
            worst_mr = mr

    return (best_i, best_mr, worst_i, worst_mr)


def summarize_all_cnts(cnt_result_file,cache_size,rebalance_strategy,algos=None):
    
    f = open(cnt_result_file,"r")
    results = f.read().split("\n\n")
    
    results_for_cs = [r for r in results if "_"+cache_size+"_" in r]
    
    (best_i, best_mr, worst_i, worst_mr) = find_best_and_worst(results_for_cs)


    if best_mr == 1.0 or worst_mr == 0.0 :
        sys.stdout = sys.__stdout__
        print(results)
        print("Error parsing file",cnt_result_file)
        exit()


    print("Best result for cache size {} and reb. strategy {}: {}".format(cache_size,rebalance_strategy,best_mr))
    print(results_for_cs[best_i])
    print()
    print("Worst result for cache size {} and reb. strategy {}: {}".format(cache_size,rebalance_strategy,worst_mr))
    print(results_for_cs[worst_i])
    print("\n\n")    

    if algos!=None:
        sys.stdout = sys.__stdout__
        print("Comparison of rebalance strategies within eviction algorithm under fixed cache size...")
        if ap.stdout_file != "default": sys.stdout = summary_best_file

        for algo in algos:
            if rebalance_strategy == "MarginalHits" and algo!="Lru2Q": continue

            results_for_algo = [r for r in results_for_cs if "_"+algo+"_" in r]
            (best_i, best_mr, worst_i, worst_mr) = find_best_and_worst(results_for_algo)

            if best_mr == 1.0 or worst_mr == 0.0 :
                sys.stdout = sys.__stdout__
                print(results)
                print("Error parsing file",cnt_result_file)
                exit()

            print("Best result for cache size {} and reb. strategy {} and algo {}: {}".format(cache_size,rebalance_strategy,algo,best_mr))
            print(results_for_algo[best_i])
            print("Worst result for cache size {} and reb. strategy {} and algo {}: {}".format(cache_size,rebalance_strategy,algo,worst_mr))
            print(results_for_algo[worst_i])
            print("Difference between best and worst in miss ratio: {}".format(worst_mr - best_mr))
            print("*"*100)

    print("-"*100,"\n\n")



def collect_cnts(file,reb):

    with open(file,"r") as f:
        stdout_str = f.read()
        stdout_str_L = stdout_str.split("\n")
    
    print(stdout_str_L[:4])

    if reb == "MarginalHits":
        strategy_triggered_s = MarginalHits_triggered_s
    elif reb == "FreeMem":
        strategy_triggered_s = FreeMem_triggered_s
    else:
        strategy_triggered_s  = STRTGY_TRIGGERED_s

    print("strategy_triggere_s:",strategy_triggered_s)
    
    res = {"total_attempts": stdout_str.count(START_REB_s),
            ABBRV[strategy_triggered_s]: stdout_str.count(strategy_triggered_s),
            ABBRV[FAILALLOC_TRIGGERED_s]: stdout_str.count(FAILALLOC_TRIGGERED_s),
          }
    
    for i,r in enumerate(FAIL_REASONS["Universal"]):
        res[ABBRV[r]] = stdout_str.count(r)
    
    for i,r in enumerate(FAIL_REASONS[reb]):
        if reb=="FreeMem" and i == 1:
            res[ABBRV[r]] = stdout_str.count(r)
        else:
            res[r] = stdout_str.count(r)
   

    hr_list = []
    hr_regex=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 
    for (i,line) in enumerate(stdout_str_L):
        if i == len(stdout_str_L) - 2: break 
        
        m = re.search(hr_regex,line) 

        if not m: continue

        hr_list.append(m.group("hit_ratio"))

    final_hr = hr_list[-1]

    res[MISS_RATIO_s] = 1-float(final_hr)

    return res



if __name__=="__main__":
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--summarize_cnt",type=str,required=True)
    p.add_argument("--output_folder",type=str,required=True) 
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--rebalance_strategies",type=str,required=True)

    p.add_argument("--cache_sizes",type=str,default="all")
    p.add_argument("--algo",type=str,default="all")
    p.add_argument("--stdout_file",type=str,default="default")

    ap = p.parse_args()  
 
    # given a trace, x axis is the cache size. y axis is the miss ratio.  
    # we want [Lru, Lru2Q, TinyLFU] * [4 rebalancing strategy] 

    if (ap.cache_sizes=="all"):
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
    
    if ap.stdout_file != "default":
        print("Redirecting stdout to",ap.stdout_file)
        summary_best_file = open(ap.stdout_file,"w")
        sys.stdout = summary_best_file
    
    if ap.summarize_cnt == "yes": 
        sys.stdout = sys.__stdout__
        print("Summarizing counts...")
        if ap.stdout_file != "default": sys.stdout = summary_best_file


        for reb in rebalance_strategies:
            for cache_size in cache_sizes:
                result_file = os.path.join(ap.output_folder,reb+".txt")
                summarize_all_cnts(result_file,cache_size,reb,algos)
        
        if ap.stdout_file != "default":
            sys.stdout = sys.__stdout__
            summary_best_file.close()
        
        exit()


    for (j,rebalance_strategy) in enumerate(rebalance_strategies):
        all_files_for_reb = os.listdir(os.path.join(ap.output_folder,rebalance_strategy))

        for (i,algo) in enumerate(algos):
            if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

            for cache_size in cache_sizes: 
                
                prefix = ap.name + "_" + algo + "_" +cache_size+"_"+rebalance_strategy

                all_output_files = [f for f in all_files_for_reb if (
                            f.startswith(prefix) and not f.endswith(".txt"))]
                
                for output_file in all_output_files:
                    output_file_ = os.path.join(ap.output_folder,rebalance_strategy,output_file)
                    print(output_file_)

                    cnt_res = collect_cnts(output_file_,rebalance_strategy)

                    print(cnt_res)
                    print()

    if ap.stdout_file != "default":
        sys.stdout = sys.__stdout__
        summary_best_file.close()
