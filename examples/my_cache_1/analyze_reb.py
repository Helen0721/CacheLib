import os
import sys
import itertools
from collections import defaultdict
import re
import json
import numpy as np
import random
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.colors as mcolors
from matplotlib.lines import Line2D
from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging
import copy

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


config_s_dict = {
                "LruTailAge": "LTAS::LTAS(Config config): ",
                "FreeMem": "MFS::MFS(Config config): ",
                "MarginalHits": "MHS::MHS(Config config): ",
                "HitsPerSlab": "HPS::HPS(Config config): "
                }

config_end_s = "Cache Initialized."

default_config_dict = {
            "LruTailAge": "tailAgeDifferenceRatio:0.25,minTailAgeDifference:100,minSlabs:1,numSlabsFreeMem:3;slabProjectionLength:1",
            "HitsPerSlab": "minDiff:100,diffRatio:0.1,minSlabs:1,numSlabsFreeMem:3,min\maxLruTailAge:0",
            "FreeMem": "minSlabs:1,numFreeSlabs:3,maxUnAllocatedSlabs:1000",
            "MarginalHits": "movingAveParam:0.3,minSlabs:1,maxFreeMemSlabs:1"
            }



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


def summarize_best_cnt(ALL_CNTS,cache_size,rebalance_strategy,algo):
    res_for_files = ALL_CNTS[cache_size][rebalance_strategy][algo]

    best_file,best_mr = "",1.0

    for file,res_for_file in res_for_files.items():
        mr = res_for_file[MISS_RATIO_s]
        if mr < best_mr:
            best_file = file
            best_mr = mr

    
    ALL_CNTS[cache_size][rebalance_strategy][algo]["best_result"] = {best_file: copy.deepcopy(res_for_files[best_file])}


def collect_cnts(file,reb):
    with open(file,"r") as f:
        stdout_str = f.read()
        stdout_str_L = stdout_str.split("\n")

    def get_final_hr():
        hr_list = []
        hr_regex=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 
        for (i,line) in enumerate(stdout_str_L):
            if i == len(stdout_str_L) - 2: break 
        
            m = re.search(hr_regex,line) 

            if not m: continue

            hr_list.append(m.group("hit_ratio"))

        final_hr = hr_list[-1]
        return final_hr

    def get_config():
        if (reb == "default"): return default_config_dict[reb]

        config_s = config_s_dict[reb]

        for line in stdout_str_L:
            if config_s in line:
                config = line.split(config_s)[-1]
                config = config.split(config_end_s)[0]
                return config
        
        print(stdout_str_L[:4])
        print("error parsing config")
        return None

    #print(stdout_str_L[:3])

    if reb == "MarginalHits":
        strategy_triggered_s = MarginalHits_triggered_s
    elif reb == "FreeMem":
        strategy_triggered_s = FreeMem_triggered_s
    elif reb == "default":
        res = {
            "total_attempts": stdout_str.count(START_REB_s),
            ABBRV[FAILALLOC_TRIGGERED_s]: stdout_str.count(FAILALLOC_TRIGGERED_s),
            MISS_RATIO_s: 1-float(get_final_hr())
        }
        return res
    else:
        strategy_triggered_s  = STRTGY_TRIGGERED_s
 
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
  
    res[MISS_RATIO_s] = 1-float(get_final_hr())

    
    res["rebParams"] = get_config()

    if res["rebParams"] == None: exit()    

    return res


def collect_all_cnts():
    ALL_RES = {cs:{reb:{algo:{} for algo in algos if (not (reb=="MarginalHits" and algo!="Lru2Q"))} for reb in rebalance_strategies} for cs in cache_sizes}
    
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
                    print("parsing for",output_file_)
                    cnt_res = collect_cnts(output_file_,rebalance_strategy)
                    ALL_RES[cache_size][rebalance_strategy][algo][output_file_] = cnt_res 

    for cache_size in cache_sizes: 
        for rebalance_strategy in rebalance_strategies:
            for algo in algos:
                summarize_best_cnt(ALL_RES,cache_size,rebalance_strategy,algo)


    return ALL_RES


if __name__=="__main__":
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True) 
    p.add_argument("--name",type=str,required=True)

    p.add_argument("--rebalance_strategies",type=str,default="all")
    p.add_argument("--cache_sizes",type=str,default="all")
    p.add_argument("--algo",type=str,default="all")
    

    ap = p.parse_args()  
  
    if (ap.cache_sizes=="all"):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",") 

    if (ap.rebalance_strategies=="all"):
        rebalance_strategies = REBALANCEING_STRATEGIES
        json_file_path = os.path.join(ap.output_folder,"all.json")
    else:
        rebalance_strategies = ap.rebalance_strategies.split(",")
        json_file_path = os.path.join(ap.output_folder,"{}.json".format("_".join(rebalance_strategies)))

    if ap.algo=="all":
        algos = ALGOS
    else:
        algos = [ap.algo]


    ALL_RES = collect_all_cnts()

    with open(json_file_path,"w") as jf:
            print("dumping to",json_file_path)
            json.dump(ALL_RES,jf,indent=5)
