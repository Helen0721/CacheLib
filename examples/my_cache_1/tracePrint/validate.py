from tqdm import tqdm
import csv
import argparse

if __name__ ==  "__main__":
    
    p = argparse.ArgumentParser()
    p.add_argument("--my",type=str,required=True)
    p.add_argument("--ref",type=str,required=True)

    ap = p.parse_args()
    
    with open(ap.my,"r") as my_f:
        my = my_f.read().split("\n")

    with open(ap.ref,"r") as ref_f:
        ref = ref_f.read().split("\n")

    for i in range(1,len(my)-1):
        if my[i] != ref[i+1]:
            print("ref:",ref[i+2],"my:",my[i], "line:",i) 
