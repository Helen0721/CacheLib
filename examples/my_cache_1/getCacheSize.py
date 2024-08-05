import subprocess 
import logging
import os
import argparse
import json

output = "TraceStats.json"

libCacheSim_path = "/mnt/cfs/libCacheSim/_build/bin/traceAnalyzer"

num_obj_str = "number of objects: "
footprt_str = "number of obj GiB: "


def GB2MB(x):
    return 1000 * x


if __name__=="__main__": 
    p = argparse.ArgumentParser()
    p.add_argument("--data",type=str,required=True)
    p.add_argument("--type",type=str,default="oracleGeneral")

    ap = p.parse_args()
     
    run_args = [libCacheSim_path,ap.data,ap.type,"--size"]

    r = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if r.returncode != 0: 
        logger.warning("traceAnalyzer may have crashed with segfault")

    stderr_str = r.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)

    stdout_str = r.stdout.decode("utf-8")
    stdout_str_L = stdout_str.split("\n")

    for line in stdout_str_L:
        if num_obj_str in line: 
            parts = line.split(num_obj_str)
            num_obj = int(parts[-1])
        elif footprt_str in line: 
            parts = line.split(footprt_str)
            footprt = float(parts[-1])
            break
    
    ten = footprt * 0.1
    one = footprt * 0.01
    tenth = footprt * 0.001
    
    final = dict()

    if (tenth < 1): 
        final["0.1%"] = "{:.0f}MB".format(GB2MB(tenth))
    else:
        final["0.1%"] = "{:.0f}GB".format(tenth)

    if (one < 1): 
        final["1%"] = "{:.0f}MB".format(GB2MB(one))
    else:
        final["1%"] = "{:.0f}GB".format(one)
    
    if (ten < 1): 
        final["10%"] ="{:.0f}MB".format(GB2MB(ten))
    else:
        final["10%"] = "{:.0f}GB".format(ten)
    
    final["res"] = stdout_str

    if os.path.exists(output):
        with open(output, 'r') as rf:
            data = json.load(rf)
    else:
        data = dict() 

    data[ap.data] = final

    with open(output,"w") as wf:
        json.dump(data, wf, indent=4)

    print("result for",ap.data, "appended to",output)
