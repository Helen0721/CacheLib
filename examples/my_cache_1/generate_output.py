from typing import List, Dict, Tuple, Union, Literal
import subprocess 
import logging
import os

Lru_path = "build/my_cache_Lru"
Lru2Q_path = "build/my_cache_Lru2Q"
TinyLFU_path = "build/my_cache_TinyLFU"

ALGOS = ["Lru","Lru2Q","TinyLFU"]

CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB",
        "8GB","16GB","32GB","64GB"]
OUTPUT_DIR = "output/"

logger = logging.getLogger("generate_token")

def run(out_file,tracepath,max_reqs,algo = "LRU",cache_size = "1GB",suffix=""):
    if algo=="Lru": run_path = Lru_path;
    elif algo=="Lru2Q": run_path = Lru2Q_path;
    elif algo=="TinyLFU": run_path = TinyLFU_path;
    else: 
        print("unsupported algorithm ", algo);
    
    print("run path:", run_path)

    run_args = [run_path, tracepath,str(max_reqs),cache_size,suffix]

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
    p.add_argument("--suffix",type=str,default="")
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--max_reqs",type=int,default=0)
    p.add_argument("--cache_sizes",type=str,default="")

    ap = p.parse_args()

    if (ap.cache_sizes==""):
        cache_sizes = CACHE_SIZES
    else:
        cache_sizes = ap.cache_sizes.split(",")
 
    for algo in ALGOS: 
        for cache_size in cache_sizes:
            if ap.suffix=="":
                output_file = OUTPUT_DIR + ap.name + "_" + algo + "_" + cache_size + ".txt"
            else:
               output_file = OUTPUT_DIR + ap.name + "_" + algo + "_" + cache_size + "_" + ap.suffix + ".txt" 
            print("running",ap.tracepath,"with", algo,"and cache_size",cache_size) 
            run(output_file,ap.tracepath,ap.max_reqs,algo=algo,cache_size=cache_size,suffix=ap.suffix)
