from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging
import os
import random

Lru_path = "build/my_cache_Lru"
Lru2Q_path = "build/my_cache_Lru2Q"
TinyLFU_path = "build/my_cache_TinyLFU"
Sieve_path = "build/my_cache_Sieve"

ALGOS = ["Lru","Lru2Q","TinyLFU","Sieve"]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB",
        "8GB","16GB","32GB","64GB"]

REB_PARAMS_DICT = {
        "LruTailAge":[  [1], #interval(1) 
                        [0.15,0.2,0.25],#tailAgeDifferenceRatio(0.25)
                        [15,50,100], #minTailAgeDifference(100)
                        [1], #minSlabs(1)
                        [1,2,3], #numSlabsFreeMem(3)
                        [1] #slabProjectionLength(1)
                      ],      
      "MarginalHits":[  [1], #interval(1)
                        [0.2,0.3,0.4],#movingAverageParam(0.3)
                        [1], #minSlabs(1)
                        [1], #maxFreeMemSlabs(1)
                    ],             
      "HitsPerSlab":[   [1], #interval(1)
                        [20,50,100], #minDiffs(100)
                        [1], #minSlabs(1)
                        [0.05,0.1,0.2], #diffRatio(0.1)
                        [1,2,3], #numSlabsFreeMem(3)
                        [0],#minLruTailAge(0)
                        [0] #maxLruTailAge(0)
                    ],                
        "FreeMem":[     [1], #interval(1)
                        [0,1], #minSlabs(1)
                        [0,1,2,3], #numSlabsFreeMem(3)
                        [1000] #maxUnAllocatedSlabs(1000)
                    ]                           
        }


OUTPUT_DIR = "output/"
logger = logging.getLogger("generate_token")


def chooseRebParams(strategy,option):
    if option == "randomized":
        allChoices = REB_PARAMS_DICT[strategy]
        return (",".join([str(random.choice(paramList)) for paramList in allChoices]))
    else: 
        return option


def run(out_file,tracepath,max_reqs,algo,cache_size,reb,rebParams,cacheStats_path):
    if algo=="Lru": run_path = Lru_path
    elif algo=="Lru2Q": run_path = Lru2Q_path
    elif algo=="TinyLFU": run_path = TinyLFU_path
    elif algo=="Sieve": run_path = Sieve_path
    else: 
        print("unsupported algorithm ", algo)
    
    if ap.suffix:
        run_path += "_" + ap.suffix
        out_file += "_" + ap.suffix
        cacheStats_path += "_" + ap.suffix

    print("run path:", run_path,", output file:",out_file, ", CacheStats file", cacheStats_path)
    
    #if ap.uniform=="yes":
    #    if os.path.isfile(out_file):
    #        print(out_file,"already exists")
    #        return

    run_args = [run_path, tracepath,str(max_reqs),cache_size,reb,rebParams,cacheStats_path]

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
    p.add_argument("--reb",type=str,required=True)
    p.add_argument("--rebParams",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--outputdir",type=str,required=True)

    p.add_argument("--suffix",type=str,default=None)
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

    for algo in algos: 
        for cache_size in cache_sizes:

            if ap.reb == "MarginalHits" and algo != "Lru2Q": 
                print("MarginalHits only works with Lru2Q")
                continue
            
            rebParams = chooseRebParams(ap.reb,ap.rebParams)

            output_file = os.path.join(ap.outputdir,ap.reb,
                    ap.name + "_" + algo + "_" + cache_size + "_" + ap.reb + "_" + rebParams)
            
            cacheStats_path = os.path.join(ap.outputdir,ap.reb,"CacheStats_{}_{}_{}_{}".format(algo,cache_size,ap.reb,rebParams))

            print("running {} with eviction algo: {},cache_size: {}, rebalancing strategy: {}, rebParams: {}.".format(
                ap.tracepath,algo,cache_size,ap.reb,rebParams)) 

            run(output_file,
                    ap.tracepath,
                    ap.max_reqs,
                    algo=algo,
                    cache_size=cache_size,
                    reb=ap.reb,
                    rebParams=ap.rebParams,
                    cacheStats_path = cacheStats_path
                    )
