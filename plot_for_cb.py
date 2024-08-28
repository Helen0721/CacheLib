import os
import sys
from matplotlib.backends.backend_pdf import PdfPages
import re
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import argparse

plot_folder = "plots"

#Evict Fails---AC: 0, Prnt AC: 0, Cncrrnt: 0, Prnt Cncrrnt: 0, Mv: 0, Prnt MV: 0
#20:45:18    2950.52M ops completed. Hit Ratio  92.07% (RAM  92.07%, NVM   0.00%)

REGEX_EvictFail = (
    r'AC:\s*(?P<AC>\d+),\s*'
    r'Prnt AC:\s*(?P<Pr_AC>\d+),\s*'
    r'Cncrrnt:\s*(?P<Cn>\d+),\s*' 
    r'Mv:\s*(?P<Mv>\d+),\s*'
    r'Prnt MV:\s*(?P<Pr_Mv>\d+)'
)
REGEX_Time_HR = r'(?P<time>\d{2}:\d{2}:\d{2})\s+(?P<ops>[\d.]+[MK]?)\s+ops completed\.\s+Hit Ratio\s+(?P<hit_ratio>[\d.]+)%'

REGEX_Final_HR = r'Hit Ratio\s*:\s*(?P<hit_ratio>[\d.]+)%'


PTYPE_FINAL_MR = "final_mr"
PTYPE_MR_OVER_TIME = "mr_over_time"
PTYPE_MR_OVER_TIME_THRESHOLD = "mr_over_time_threshold"
PTYPE_EVCIT_FAIL_AC = "evict_fail_ac"
PTYPE_NUM_OPS_OVER_TIME = "num_ops_over_time"




'''
get       :   772,230/s, success   :  93.17%
couldExist:         0/s, success   :   0.00%
set       :   126,776/s, success   : 100.00%
del       :    11,113/s, found     :   5.78%
'''
REGEX_GET = r'get\s*:\s*(?P<get_rate>[\d,]+)/s,\s*success\s*:\s*(?P<get_success>[\d.]+)%'
REGEX_SET = r'set\s*:\s*(?P<set_rate>[\d,]+)/s,\s*success\s*:\s*(?P<set_success>[\d.]+)%'
REGEX_DEL = r'del\s*:\s*(?P<del_rate>[\d,]+)/s,\s*found\s*:\s*(?P<del_found>[\d.]+)%'

#COLORS=['tab:green', 'tab:red', 'tab:blue','tab:brown',
#        'tab:pink','tab:olive','tab:cyan','tab:orange',
#        'tab:purple','tab:grey'
#        ]

colors = ['tab:green','tab:orange','tab:blue']

plot_folder = "plots"

threshold = 60


def plot(all_res,
        plot_name,
        plot_title):
    
    final_hrs = [res["final_hr"] for res in all_res]
    hr_lists = [res["hr_list"] for res in all_res]
    AC_lists = [res["AC_list"] for res in all_res]
    ops_lists = [res["ops_list"] for res in all_res]
    ts_lists = [res["ts_list"] for res in all_res]
    labels = [res["label"] for res in all_res]    

    num_lines = len(ts_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return
    
    if not os.path.isdir(plot_folder):
        os.mkdir(plot_folder) 

    plot_fname = os.path.join(ap.dir,plot_folder,plot_name + ".pdf")
    #plot_fname = os.path.join(plot_folder,"test.pdf")
    pp = PdfPages(plot_fname)
    
    # -----------------------plotting the final average miss ratio-----------------------
    
    if PTYPE_FINAL_MR in PLOT_TYPES:
        plt.figure(figsize=(6,4))

	    if ap.limit: 
	        print("calculating average miss ratios from snapshot of",ap.limit,"minutes")
	        final_hrs = [sum(hr_list[:ap.limit])/len(hr_list[:ap.limit]) for hr_list in hr_lists]
	
	    final_mrs = [1-hr for hr in final_hrs]
	     
	    plt.barh(labels, final_mrs,color=colors[:len(labels)])
	    plt.title("Final Miss Ratio-" + plot_title) 
	    
	    plt.xlabel("Final Miss Ratio",fontsize=8) 
	    plt.xticks(fontsize=10)
	    plt.xlim(min(final_mrs)-0.01, max(final_mrs)+0.01)
	
	    plt.ylabel("Eviction Algorithms",fontsize=8)
	
	    plt.tight_layout(pad=1.0)
	    pp.savefig()
	    plt.close()


    # -----------------------plotting miss ratio over time-----------------------
    if PTYPE_MR_OVER_TIME in PLOT_TYPES:
	
	    plt.figure()
	
	    for i in range(num_lines): 
	        hr_list = hr_lists[i]
	        mr_list = [1-hr for hr in hr_list] 
	        ts_list = ts_lists[i]   
	        if ap.limit:
	            mr_list = mr_list[:ap.limit]
	            ts_list = ts_list[:ap.limit]
	        plt.plot(ts_list, mr_list,label=labels[i],color=colors[i])
	
	    plt.title("miss ratio-" + plot_title)
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
    

    # -----------------------plotting miss ratio over time (with threshold)-----------------------
    if PTYPE_MR_OVER_TIME_THRESHOLD in PLOT_TYPES:
	    plt.figure()
	    for i in range(num_lines): 
	        hr_list = hr_lists[i][threshold:]    
	        mr_list = [1-hr for hr in hr_list]
	        ts_list = ts_lists[i][threshold:]
	        if ap.limit:
	            mr_list = mr_list[:ap.limit-threshold]
	            ts_list = ts_list[:ap.limit-threshold] 
	        plt.plot(ts_list, mr_list,label=labels[i],color=colors[i])
	
	    plt.title("miss ratio after 60 mins-" + plot_title)
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


    # -----------------------plotting Eviction Failure from AC over time-----------------------
    if PTYPE_EVCIT_FAIL_AC in PLOT_TYPES:

	    plt.figure()
	    for i in range(num_lines): 
	        AC_list = AC_lists[i][:-1] 
	        ts_list = ts_lists[i]
	        if ap.limit:
	            AC_list = AC_list[:ap.limit]
	            ts_list = ts_list[:ap.limit]
	        plt.plot(ts_list,AC_list,label=labels[i],color=colors[i])
	
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

    # -----------------------plotting throughput (total # ops) over time-----------------------
    if PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES:
	    plt.figure() 
	    for i in range(num_lines): 
	        ops_list = ops_lists[i]
	        ts_list = ts_lists[i]
	        if ap.limit:
	            ops_list = ops_list[:ap.limit]
	            ts_list = ts_list[:ap.limit]
	        plt.plot(ts_list,ops_list,label=labels[i],color=colors[i])
	
	    plt.title("operations completed-" + plot_title)
	    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
	                        loc="upper right", fontsize="10", frameon=False) 
	    frame = legend.get_frame() 
	    frame.set_facecolor("0.9") 
	    frame.set_edgecolor("0.9")
	    plt.grid(axis="y", linestyle="--") 
	    plt.xlabel("Time",fontsize=8) 
	    plt.xticks(fontsize=10)
	    plt.ylabel("Ops completed",fontsize=8)
	    plt.yticks(fontsize=10)
	    plt.tight_layout(pad=1.0)
	    pp.savefig()
	    plt.close()

    # -----------------------plotting Throughput Data-----------------------
    if PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES:

	    GRs = [res["get_rate"] for res in all_res]
	    SRs = [res["set_rate"] for res in all_res]
	    DRs = [res["del_rate"] for res in all_res]
	    
	    GSs = [res["get_success"] for res in all_res]
	    SSs = [res["set_success"] for res in all_res]
	    DFs = [res["del_found"] for res in all_res]
	
	    thpt_labels =[["Get Rate","Set Rate","Delete Rate"],
	                  ["Get success","Set Success", "Delete Found"]
	                 ]
	    thpt_data = [[GRs,SRs,DRs],
	                 [GSs,SSs,DFs]
	                ]
	    thpt_x_labels = ["Op/sec","Success/Total"]  
	    
	    x_offsets = [[10**5,10**4,10**3],
	                [0.02,0.02,0.02]
	                ]
	    figsize = (15,5)
	    if "hit_ratio" and "graph_cache_" in ap.dir:
	        thpt_labels[0].pop()
	        thpt_labels[1].pop()
	        thpt_data[0].pop()
	        thpt_data[1].pop()
	        x_offsets[0].pop()
	        x_offsets[1].pop()
	
	    formatter = ticker.ScalarFormatter(useOffset=False, useMathText=True) 
	    formatter.set_scientific(True)
	    formatter.set_powerlimits((-2, 2))  # Adjust these limits to control when scientific notation is used
	    fig, axs = plt.subplots(nrows=len(thpt_labels), ncols=len(thpt_labels[0]), figsize=(15,5))
	    for r in range(len(thpt_labels)):
	        for i in range(len(thpt_labels[0])):
	            data = thpt_data[r][i]
	            x_offset = x_offsets[r][i]
	            #print(data)
	            axs[r,i].barh(labels, data, color=colors[:len(labels)])
	            axs[r,i].set_xlabel(thpt_x_labels[r])
	            axs[r,i].set_title(thpt_labels[r][i])
	            axs[r,i].set_xlim(min(data)-x_offset,max(data)+x_offset) 
	            axs[r,i].xaxis.set_major_formatter(formatter)
	
	    fig.suptitle("Throughput data-" + plot_title,fontsize=12)   
	    plt.tight_layout(rect=[0, 0, 1, 0.9999])
	
	    pp.savefig(fig)
	    plt.close()




    pp.close()

    print("plots saved to {}".format(plot_fname))


def parse(f_path):
    
    print("parsing for",f_path)

    with open(f_path,"r") as f:
        stdout = f.read().splitlines()

    time = 1
    hr_list,AC_list,ops_list,ts_list = [],[],[],[]
    
    for line in stdout:
        
        hr_time_m = re.search(REGEX_Time_HR,line)
        if hr_time_m: 
            ops = float(hr_time_m.group('ops')[:-1]) * (10**6)
            hit_ratio = float(hr_time_m.group('hit_ratio')) * 0.01
            
            ops_list.append(ops)
            hr_list.append(hit_ratio)
            ts_list.append(time)
            time += 1

            continue
        
        final_hr_m = re.search(REGEX_Final_HR,line)
        if final_hr_m:
            final_hr = float(final_hr_m.group('hit_ratio')) * 0.01 

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
            continue

        get_m = re.search(REGEX_GET,line)
        if get_m:
            get_rate = int(get_m.group("get_rate").replace(",",""))
            get_success = float(get_m.group("get_success")) * 0.01
            continue
        
        set_m = re.search(REGEX_SET,line)
        if set_m:
            set_rate = int(set_m.group("set_rate").replace(",",""))
            set_success = float(set_m.group("set_success")) * 0.01
            continue

        del_m = re.search(REGEX_DEL,line)
        if del_m:
            del_rate = int(del_m.group("del_rate").replace(",",""))
            del_found = float(del_m.group("del_found")) * 0.01
            continue

    res = {
            "final_hr": final_hr,
            "hr_list":hr_list,
            "AC_list":AC_list,
            "ops_list": ops_list,
            "ts_list": ts_list,
            "get_rate": get_rate,
            "get_success": get_success,
            "set_rate": set_rate,
            "set_success": set_success,
            "del_rate": del_rate,
            "del_found": del_found
            }

    return res 

if __name__=="__main__":
    p = argparse.ArgumentParser()
    
    p.add_argument("--dir",type=str,required=True)
    p.add_argument("--algos",type=str,required=True)
    p.add_argument("--cache_size",type=str,required=True)
    p.add_argument("--thread",type=int,required=True)
    
    p.add_argument("--limit",type=int,default=None)
    
    p.add_argument("--types",type=str,default=)


    ap = p.parse_args()
    
    algos = sorted(ap.algos.split(",")) 
    
    ALL_RES = []

    for algo in algos:
        log_file_path = os.path.join(ap.dir,"{}_t{}_{}_log".format(ap.cache_size,ap.thread,algo))
        
        res_for_algo = parse(log_file_path)
        res_for_algo["label"] = algo

        ALL_RES.append(res_for_algo)
        
        print("Time executed for {}: {}".format(algo,res_for_algo["ts_list"][-1]))
        

    plot_name = "{}_t{}_{}".format(ap.cache_size,ap.thread,",".join(algos))
    if ap.limit:
        plot_name += "_" + str(ap.limit)
    plot_title = plot_name

    plot(ALL_RES,
        plot_name,
        plot_title)
