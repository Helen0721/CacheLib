import os
import sys
from matplotlib.backends.backend_pdf import PdfPages
import re
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import argparse

plot_folder = "plots"

#Evict Fails---AC: 0, Prnt AC: 0, Cncrrnt: 0, Prnt Cncrrnt: 0, Mv: 0, Prnt MV: 0
#20:45:18    2950.52M ops completed. Hit Ratio  92.07% (RAM  92.07%, NVM   0.00%)

REGEX_EvictFail = (
    r'AC:\s*(?P<AC>\d+),\s*'
    r'Prnt AC:\s*(?P<Pr_AC>\d+),\s*'
    r'Cncrrnt:\s*(?P<Cn>\d+),\s*'
    r'Prnt Cncrrnt:\s*(?P<Pr_Cn>\d+),\s*'
    r'Mv:\s*(?P<Mv>\d+),\s*'
    r'Prnt MV:\s*(?P<Pr_Mv>\d+)'
)
REGEX_Time_HR = r'(?P<time>\d{2}:\d{2}:\d{2})\s+(?P<ops>[\d.]+[MK]?)\s+ops completed\.\s+Hit Ratio\s+(?P<hit_ratio>[\d.]+)%'

plot_folder = "plots"

threshold = 60


def plot(hr_lists,
        AC_lists,
        ts_lists,
        labels,
        plot_name,
        plot_title):
    
    num_lines = len(ts_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return
    
    if not os.path.isdir(plot_folder):
        os.mkdir(plot_folder) 

    plot_fname = os.path.join(plot_folder,plot_name + ".pdf")
    pp = PdfPages(plot_fname)

    # plotting miss ratio over time:
    plt.figure()
    
    ts_list,min_len = ts_lists[0],len(ts_lists[0])
    for L in ts_lists: 
        if len(L) < min_len:
            ts_list,min_len = L,len(L)

    for i in range(num_lines): 
        hr_list = hr_lists[i][:min_len]
        mr_list = [1-hr for hr in hr_list] 
        
        plt.plot(ts_list, mr_list,label=labels[i])

    plt.title("hit ratio-" + plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="10", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time",fontsize=8) 
    plt.xticks(fontsize=10)
    plt.ylabel("Miss Ratio",fontsize=8)
    plt.yticks(fontsize=10)
    plt.tight_layout(pad=1.0)
    pp.savefig()
    plt.close()
    

    # plotting miss ratio over time (with threshold 60 minutes):
    plt.figure()
    ts_list_ = ts_list[threshold:]
    for i in range(num_lines): 
        hr_list = hr_lists[i][threshold:min_len]    
        mr_list = [1-hr for hr in hr_list]

        plt.plot(ts_list_, mr_list,label=labels[i])

    plt.title("hit ratio after 60 mins-" + plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="10", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time",fontsize=8) 
    plt.xticks(fontsize=10)
    plt.ylabel("Miss Ratio",fontsize=8)
    plt.yticks(fontsize=10)
    plt.tight_layout(pad=1.0)
    pp.savefig()
    plt.close()



    # plotting AC over time
    plt.figure()
    for i in range(num_lines): 
        AC_list = AC_lists[i][:min_len] 
        plt.plot(ts_list,AC_list,label=labels[i])

    plt.title("Evict Fail from Access Container-" + plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="10", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Time",fontsize=8) 
    plt.xticks(fontsize=10)
    plt.ylabel("Evict Fail from AC",fontsize=8)
    plt.yticks(fontsize=10)
    plt.tight_layout(pad=1.0)
    pp.savefig()
    plt.close()



    pp.close()

    print("plots saved to {}".format(plot_fname))


def parse(f_path):
    with open(f_path,"r") as f:
        stdout = f.read().splitlines()

    time = 1
    hr_list,AC_list,ts_list = [],[],[]
    start_time = None

    for line in stdout:
        
        hr_time_m = re.search(REGEX_Time_HR,line)
        if hr_time_m: 
            ops = hr_time_m.group('ops')
            hit_ratio = float(hr_time_m.group('hit_ratio')) * 0.01
                         
            hr_list.append(hit_ratio)
            ts_list.append(time)
            time += 1

            continue
        
        ef_m = re.search(REGEX_EvictFail,line)
        if ef_m:
            AC = int(ef_m.group("AC"))
            Pr_AC =int(ef_m.group("Pr_AC"))
            Cn = int(ef_m.group("Cn"))
            Pr_Cn = int(ef_m.group("Pr_Cn"))
            Mv = int(ef_m.group("Mv"))
            Pr_Mv = int(ef_m.group("Pr_Mv"))

            if Pr_AC!=0 or Cn!=0 or Pr_Cn!=0 or Mv!=0 or Pr_Mv!=0:
                print("Evict Failures from other reasons occur:",line)
             
            AC_list.append(AC) 

    return hr_list,AC_list,ts_list


if __name__=="__main__":
    p = argparse.ArgumentParser()

    p.add_argument("--algos",type=str,required=True)
    p.add_argument("--cache_size",type=str,required=True)
    p.add_argument("--thread",type=int,required=True)

    ap = p.parse_args()
    
    algos = ap.algos.split(",")
    
    hr_lists,AC_lists,ts_lists,labels = [],[],[],[]

    for algo in algos:
        log_file_path = "{}_t{}_{}_log".format(ap.cache_size,ap.thread,algo)

        hr_list,AC_list,ts_list = parse(log_file_path)

        hr_lists.append(hr_list)
        AC_lists.append(AC_list)
        ts_lists.append(ts_list)
        labels.append(algo)

        print(hr_list[-10:]) 


    plot_name = "{}_t{}_{}".format(ap.cache_size,ap.thread,ap.algos)
    plot_title = plot_name

    plot(hr_lists,
        AC_lists,
        ts_lists,
        labels,
        plot_name,
        plot_title)
