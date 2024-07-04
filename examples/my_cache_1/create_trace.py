import csv
import os
import numpy as np
import subprocess

header = ["time","object","size","next_access_vtime"]
dataPath = "/disk/CacheLib/examples/my_cache_1/data"
traceConvPath = "/disk/libCacheSim/_build/bin/traceConv"
csvHeaderFormat = "time-col=1,obj-id-col=2,obj-size-col=3,obj-id-is-num=1"

if __name__ == "__main__":
    import argparse

    p = argparse.ArgumentParser()

    p.add_argument("--out",type=str,required=True)
    p.add_argument("--size",type=int,required=True)
    p.add_argument("--t",type=str,default=None)
    p.add_argument("--conv",type=str,default="no")
    p.add_argument("--n",type=int,default=10)
    p.add_argument("--r",type=float,default=0.5)

    ap = p.parse_args() 
    res = []

    if ap.t:
        traces = ap.t.split(",")
        for obj_id in traces:
            entry = [0,obj_id,ap.size,0]
            res.append(entry) 
    else:
        base = []
        for i in range(ap.n):
            entry = [0,i,ap.size,0]
            base.append(entry)
  
        for i in range(ap.n):
            if np.random.choice([True,False],p=[ap.r,1-ap.r]):
                res.append(res[i])
    #print(res)

    csv_trace_path = os.path.join(dataPath,ap.out+".csv")
    with open(csv_trace_path,"w") as csvF:
        csvWriter = csv.writer(csvF)
        csvWriter.writerow(header)
        for row in res:
            csvWriter.writerow(row)

    
    if ap.conv=="yes":
        bin_trace_path = os.path.join(dataPath,ap.out+".oracleGeneral")

        run_args = [traceConvPath, csv_trace_path, "csv",
                    "-o", bin_trace_path,
                    "-t", csvHeaderFormat, 
                    ]

        print(run_args)   
        result = subprocess.run(run_args, capture_output=True, text=False)

        if result.returncode == 0:
            print("Success")
            print(result.stdout)
        else:
            print("Error")
            print(result.stderr)


