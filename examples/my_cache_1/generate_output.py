from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging
import os
import random
import zstandard as zstd

Lru_path = "build/my_cache_Lru"
Lru2Q_path = "build/my_cache_Lru2Q"
TinyLFU_path = "build/my_cache_TinyLFU"
Sieve_path = "build/my_cache_Sieve"

ALGOS = ["Lru","Lru2Q","TinyLFU","Sieve"]

LOG_CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB",
        "8GB","16GB","32GB","64GB"]

TRACE_STATS_path = "TraceStats.json"

zstdThreshold = 1024 * 1024

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

REBALANCE_STRATEGY = ["LruTailAge","MarginalHits","HitsPerSlab","FreeMem","default"]


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
        return
    
    if ap.suffix:
        run_path += "_" + ap.suffix
        out_file += "_" + ap.suffix 

    print("run path:", run_path,", output file:",out_file)
    
    #if ap.uniform=="yes":
    #    if os.path.isfile(out_file):
    #        print(out_file,"already exists")
    #        return
    
    run_args = [run_path, tracepath,str(max_reqs),cache_size,reb,rebParams]
    
    if not os.path.isfile(cacheStats_path):
        print("saving CacheStats to",cacheStats_path)
        run_args.append(cacheStats_path)

    p = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if p.returncode != 0: 
        logger.warning("cachesim may have crashed with segfault")
        print(p.stdout.decode("utf-8"))
        return

    stderr_str = p.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)

    stdout_str = p.stdout.decode("utf-8")
    
    with open(out_file,"w") as f:
        f.write(stdout_str) 
    
    if os.path.getsize(out_file) > zstdThreshold:
        compressed_out_file = out_file  + '.zst'

        with open(out_file, 'rb') as f_in, open(compressed_out_file, 'wb') as f_out:
            compressor = zstd.ZstdCompressor(level=8)  # Compression level 3, you can adjust this
            compressor.copy_stream(f_in, f_out)

        os.remove(out_file)
        print("Compressed stdout to {} and deleted the original {}".format(compressed_out_file,out_file))
    else:
        print("Output saved to {}. no compression needed".format(out_file))


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
    
    if ap.reb not in REBALANCE_STRATEGY:
        print("unsupported rebalence strategy ",ap.reb)
        exit()
    
    if (ap.cache_sizes=="log"):
        cache_sizes = LOG_CACHE_SIZES

    elif ("%" in ap.cache_sizes):
        import json
        with open(TRACE_STATS_path,"r") as trace_stats_f:
            stats = json.load(trace_stats_f)[ap.tracepath]
        
        footprint = float(stats["footprint"])  
        if "all" in ap.cache_sizes:
            cache_sizes = [stats["10%"],stats["1%"],stats["0.1%"]]
        else:
            parts = ap.cache_sizes.split(",")
            cache_sizes = [stats[part] for part in parts]    
    else:
        cache_sizes = ap.cache_sizes.split(",")
    

    if (ap.algos=="all"):
        algos = ALGOS
    else:
        algos = ap.algos.split(",") 

    for algo in algos: 
        for cache_size in cache_sizes:
            if footprint < 10:
                print("Returnning. {} cache footprint of {}GB is too small".format(ap.tracepath,stats["footprint"]))
                continue

            if "GB" in cache_size:
                if int(cache_size.split("GB")[0]) > 200:
                    print("cache size of {} too big".format(cache_size))
                    continue

            if ap.reb == "MarginalHits" and algo != "Lru2Q":
                print("MarginalHits only works with Lru2Q")
                continue
            if algo == "Sieve" and ap.reb=="LruTailAge":
                print("Sieve doesn't work with LruTailAge")
                continue
            
            rebParams = chooseRebParams(ap.reb,ap.rebParams)
            
            if not os.path.exists(os.path.join(ap.outputdir,ap.reb)):
                os.makedirs(os.path.join(ap.outputdir,ap.reb))
                print("Directory {} created".format(os.path.join(ap.outputdir,ap.reb)) )
            elif not os.path.isdir(os.path.join(ap.outputdir,ap.reb)):
                print("The path {} exists but is not a directory.".format(os.path.join(ap.outputdir,ap.reb)))
                continue

            output_file = os.path.join(ap.outputdir,ap.reb,
                    ap.name + "_" + algo + "_" + cache_size + "_" + ap.reb + "_" + rebParams)
            
            cacheStats_path = os.path.join(ap.outputdir,"{}_CacheStats".format(ap.name))

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
