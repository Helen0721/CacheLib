from tqdm import tqdm
import csv
import argparse

if __name__ ==  "__main__":
    
    p = argparse.ArgumentParser()
    p.add_argument("--my",type=str,required=True)
    p.add_argument("--ref",type=str,required=True)
    p.add_argument("--my_start_idx",type=int,default=0)
    p.add_argument("--ref_start_idx",type=int,default=0)

    ap = p.parse_args()
    
    with open(ap.my,"r") as my_f:
        my = my_f.read().split("\n")

    with open(ap.ref,"r") as ref_f:
        ref = ref_f.read().split("\n")

    i,j = ap.my_start_idx, ap.ref_start_idx
    while i < len(my) and j < len(ref):
        if my[i] != ref[j]:
            print("ref[{}]:{},my[{}]:{}".format(j,ref[j],i,my[i]))
        i += 1
        j += 1
