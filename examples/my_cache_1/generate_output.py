from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging
import os
import random

Lru_path = "build/my_cache_Lru_reb"
Lru2Q_path = "build/my_cache_Lru2Q_reb"
TinyLFU_path = "build/my_cache_TinyLFU_reb"

ALGOS = ["Lru","Lru2Q","TinyLFU"]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB",
        "8GB","16GB","32GB","64GB"]

REB_PARAMS_DICT = {
        "LruTailAge":[#ratio,kLTAMinSlabs,slabProjectionLength,numSlabsFreeMem,interval
                      [0.02,0.05,0.1,0.15,0.2],
                      [1,2,3,4,5,6,7,8,9,10],
                      [0,1,2,3],
                      [1,2,3,4,5,6,7,8,9,10],
                      [1,2,3,4,5]
                      ],              
        "HitsPerSlab":[[1,2,3,4,5],[1,2,3,4,5]],              #minSlabs,interval
        "MarginalHits":[[1,2,3,4,5]],                #interval
        "FreeMem":[[1,2,3,4,5],[1,2,3,4,5]]                   #minSlabs,interval
        }


OUTPUT_DIR = "output/"
logger = logging.getLogger("generate_token")


def chooseRebParams(strategy,option):
    if option == "default": return "default"
    allChoices = REB_PARAMS_DICT.get(strategy,[])
    if allChoices == []: 
        return "default"
    else: 
        return (",".join([str(random.choice(paramList)) for paramList in allChoices]))


def run(out_file,tracepath,max_reqs,algo,cache_size,reb):
    if algo=="Lru": run_path = Lru_path;
    elif algo=="Lru2Q": run_path = Lru2Q_path;
    elif algo=="TinyLFU": run_path = TinyLFU_path;
    else: 
        print("unsupported algorithm ", algo);
    
    print("run path:", run_path,"output file:",out_file)

    rebParams = "default"

    run_args = [run_path, tracepath,str(max_reqs),cache_size,reb,rebParams]

    p = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if p.returncode != 0: 
        logger.warning("cachesim may have crashed with segfault")

    stderr_str = p.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)

    stdout_str = p.stdout.decode("utf-8")

    with open(out_file,"w") as f:
        f.write(stdout_str) 


if __name__=="__main__":
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--tracepath",type=str,required=True)
    p.add_argument("--rebParams",type=str,required=True)
    p.add_argument("--reb",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--outputdir",type=str,required=True)

    p.add_argument("--algos",type=str,default="all")
    p.add_argument("--max_reqs",type=int,default=0)
    p.add_argument("--cache_sizes",type=str,default="")

    ap = p.parse_args()

    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",")

    if (ap.algos=="all"):
        algos = ALGOS
    else:
        algos = ap.algos.split(",")

    if not ap.outputdir.endswith("/"): ap.outputdir += "/"

    for algo in algos: 
        for cache_size in cache_sizes:
            #rebParams = chooseRebParams(ap.suffix,ap.rebParams)

            output_file = ap.outputdir  +  ap.name + "_" + algo + "_" + cache_size + "_" + ap.reb + ".txt"        
            
            print("running {} with eviction algo: {},cache_size: {}, rebalancing strategy: {}.".format(
                ap.tracepath,algo,cache_size,ap.reb))
            run(output_file,ap.tracepath,ap.max_reqs,algo=algo,cache_size=cache_size,reb=ap.reb)
