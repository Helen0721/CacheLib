import os
import sys
from matplotlib.backends.backend_pdf import PdfPages
import re
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import argparse

plot_folder = "plots"
threshold = 60

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

REGEX_EVICTED_ITEM_AGE = r"^Evicted Item Age:\s*(?P<evicted_item_age>[\d]+)$"
REGEX_EVICT_DURATION = r"^Evict Duration:\s*(?P<evict_duration>\d+)$"


PTYPE_FINAL_MR = "f_mr"
PTYPE_MR_OVER_TIME = "mr_ot"
PTYPE_MR_OVER_TIME_THRESHOLD = "mr_ot_thrld"
PTYPE_EVCIT_FAIL_AC = "ef_ac"
PTYPE_NUM_OPS_OVER_TIME = "#op_ot"
PTYPE_FINAL_THPT_DATA = "f_thpt_d"

PTYPE_EVICTED_ITEM_AGE = "eia"
PTYPE_EVICT_DURATION = "ed"

PTYPE_ALL_NORMAL = ",".join([PTYPE_FINAL_MR,PTYPE_MR_OVER_TIME,PTYPE_MR_OVER_TIME_THRESHOLD,
                    PTYPE_EVCIT_FAIL_AC,PTYPE_NUM_OPS_OVER_TIME,PTYPE_FINAL_THPT_DATA])
PTYPE_ALL = ",".join([PTYPE_FINAL_MR,PTYPE_MR_OVER_TIME,PTYPE_MR_OVER_TIME_THRESHOLD,
                    PTYPE_EVCIT_FAIL_AC,PTYPE_NUM_OPS_OVER_TIME,PTYPE_FINAL_THPT_DATA,
                    PTYPE_EVICTED_ITEM_AGE,PTYPE_EVICT_DURATION]
                    )

PTYPE_HELP_MSG ="; ".join(
          [ "final miss ratio: " + PTYPE_FINAL_MR,
            "miss ratio over time: " + PTYPE_MR_OVER_TIME,
            "miss ratio over time above threshold " + str(threshold) + ": " + PTYPE_MR_OVER_TIME_THRESHOLD,
            "evict fail from access container: " + PTYPE_EVCIT_FAIL_AC,
            "num ops completed over time: " + PTYPE_NUM_OPS_OVER_TIME,
            "final throughput data: " + PTYPE_FINAL_THPT_DATA ,
            "evicted item age: " + PTYPE_EVICTED_ITEM_AGE ,
            "evict duration: " + PTYPE_EVICT_DURATION
          ])


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



def plot(all_res,
        plot_name,
        plot_title):
    
    final_hrs = [res["final_hr"] for res in all_res]
    hr_lists = [res["hr_list"] for res in all_res]
    AC_lists = [res["AC_list"] for res in all_res]
    ops_lists = [res["ops_list"] for res in all_res]
    ts_lists = [res["ts_list"] for res in all_res]
    labels = [res["label"] for res in all_res]    
    
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
        #plt.xlim(min(final_mrs)-0.01, max(final_mrs)+0.01)
	
        plt.ylabel("Eviction Algorithms",fontsize=8)
	
        plt.tight_layout(pad=1.0)
        pp.savefig()
        plt.close()


    # -----------------------plotting miss ratio over time-----------------------
    if PTYPE_MR_OVER_TIME in PLOT_TYPES:
	
        plt.figure()
        num_lines = len(hr_lists)	
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
        num_lines = len(hr_lists)
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
        num_lines = len(AC_lists)
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
        num_lines = len(op_lists)
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

    # -----------------------plotting Final Throughput Data-----------------------
    if PTYPE_FINAL_THPT_DATA in PLOT_TYPES:

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
	            #axs[r,i].set_xlim(min(data)-x_offset,max(data)+x_offset) 
	            axs[r,i].xaxis.set_major_formatter(formatter)
	
	    fig.suptitle("Throughput data-" + plot_title,fontsize=12)   
	    plt.tight_layout(rect=[0, 0, 1, 0.9999])
	
	    pp.savefig(fig)
	    plt.close()

    
    # -----------------------plotting the evicted item age over time-----------------------
    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES:
        evicted_item_ages = [res["evicted_item_ages"] for res in ALL_RES]
        plt.figure()
        num_lines = len(evicted_item_ages)
        for i in range(num_lines): 
            eia_list = evicted_item_ages[i] 
            num_eviction_list = [i for i in range(1,len(eia_list)+1)] 
            plt.plot(num_eviction_list,eia_list,label=labels[i],color=colors[i])
	
        plt.title("Evicted Item Ages (in sec)-" + plot_title)
        legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
	                        loc="upper right", fontsize="10", frameon=False) 
        frame = legend.get_frame() 
        frame.set_facecolor("0.9") 
        frame.set_edgecolor("0.9")
        plt.grid(axis="y", linestyle="--") 
        plt.xlabel("Number of Evictions",fontsize=8) 
        plt.xticks(fontsize=10)
        plt.ylabel("Evicted Item Ages (in sec)",fontsize=8)
        plt.yticks(fontsize=10)
        plt.tight_layout(pad=1.0)
        pp.savefig()
        plt.close()
    
    # -----------------------plotting the evicted item age over time and bar plot for counts-----------------------
    if PTYPE_EVICT_DURATION in PLOT_TYPES:
        evict_durations = [res["evict_durations"] for res in ALL_RES]
        plt.figure()
        num_lines = len(evict_durations)
        for i in range(num_lines): 
            ed_list = evict_durations[i] 
            num_eviction_list = [i for i in range(1,len(ed_list)+1)] 
            plt.plot(num_eviction_list,ed_list,label=labels[i],color=colors[i])
	
        plt.title("Evict Duration-" + plot_title)
        legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
	                        loc="upper right", fontsize="10", frameon=False) 
        frame = legend.get_frame() 
        frame.set_facecolor("0.9") 
        frame.set_edgecolor("0.9")
        plt.grid(axis="y", linestyle="--") 
        plt.xlabel("Number of Evictions",fontsize=8) 
        plt.xticks(fontsize=10)
        plt.ylabel("Evict Duration (in nanosec)",fontsize=8)
        plt.yticks(fontsize=10)
        plt.tight_layout(pad=1.0)
        pp.savefig()
        plt.close()
        

        plt.figure()
        ed_cnt_buckets = [1000,5000,10000,40000]
        label_for_ed_cnts = ["0~1 ms","1~5 ms", "5~10 ms", "10~40 ms","beyond 40 ms"]
        
        all_cnts = []
        
        for algo_i in range(len(labels)):
            # calculate the ed_cnt_bucket for one specific algo
            ed_list = evict_durations[algo_i]
            cnts = [0 for _ in range(len(label_for_ed_cnts))]
            
            for ed in ed_list:
                if ed < ed_cnt_buckets[0]: cnts[0] += 1
                elif ed < ed_cnt_buckets[1]: cnts[1] += 1
                elif ed < ed_cnt_buckets[2]: cnts[2] += 1
                elif ed < ed_cnt_buckets[3]: cnts[3] += 1
                else: cnts[4] += 1

            all_cnts.append(cnts)

        num_subplots = len(label_for_ed_cnts)
        fig, axs = plt.subplots(num_subplots,figsize=(10, 10))        
        
        for i in range(num_subplots):
            cnts_for_bucket = [cnt_for_algo[i] for cnt_for_algo in all_cnts]
            print(cnts_for_bucket,labels)
            axs[i].barh(labels,cnts_for_bucket,color=colors)
            axs[i].set_xlabel("Counts",fontsize=8) 
            axs[i].set_title("Evict Duration {}".format(label_for_ed_cnts[i]),fontsize=8) 
        
        plt.tight_layout(pad=1.0)
        pp.savefig(fig)
        plt.close() 


    pp.close()

    print("plots saved to {}".format(plot_fname))


def parse(f_path,line_limit):
    
    print("parsing for",f_path)

    with open(f_path,"r") as f:
        stdout = f.read().splitlines()

    time = 1
    hr_list,AC_list,ops_list,ts_list,eias,eds = [],[],[],[],[],[]
    final_hr,get_rate,get_success,set_rate,set_success,del_rate,del_found =-1,-1,-1,-1,-1,-1,-1

    for (line_i,line) in enumerate(stdout):
        if line_limit and line_i > line_limit: break
        
        if "n_iters" in line:
            print("sieve operateHand n_iters greater than 1:",line)
        
        if PTYPE_MR_OVER_TIME in PLOT_TYPES:
            hr_time_m = re.search(REGEX_Time_HR,line)
            if hr_time_m: 
                ops = float(hr_time_m.group('ops')[:-1]) * (10**6)
                hit_ratio = float(hr_time_m.group('hit_ratio')) * 0.01
            
                ops_list.append(ops)
                hr_list.append(hit_ratio)
                ts_list.append(time)
                time += 1
                continue
                
        if PTYPE_FINAL_MR in PLOT_TYPES:

            final_hr_m = re.search(REGEX_Final_HR,line)
            if final_hr_m:
                final_hr = float(final_hr_m.group('hit_ratio')) * 0.01 

                continue

        if PTYPE_EVCIT_FAIL_AC in PLOT_TYPES:
            ef_m = re.search(REGEX_EvictFail,line)
            if ef_m:
                AC = int(ef_m.group("AC"))
                Pr_AC =int(ef_m.group("Pr_AC"))
                Cn = int(ef_m.group("Cn")) 
                Mv = int(ef_m.group("Mv"))
                Pr_Mv = int(ef_m.group("Pr_Mv"))

                if Pr_AC!=0 or Cn!=0 or Mv!=0 or Pr_Mv!=0:
                    print("Evict Failures from other reasons occur:",line)
             
                AC_list.append(AC)
                continue

        if PTYPE_FINAL_THPT_DATA in PLOT_TYPES:

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
        
        if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES:
            eia_m = re.match(REGEX_EVICTED_ITEM_AGE,line)
            if eia_m:
                eia = int(eia_m.group("evicted_item_age"))
                if eia > 50:
                    #print("not aligned printing around line",line_i,line)
                    continue
                eias.append(eia) 
                continue
        
        if PTYPE_EVICT_DURATION in PLOT_TYPES: 
            ed_m = re.match(REGEX_EVICT_DURATION,line)
            if ed_m:  
                ed = int(ed_m.group("evict_duration")) 
                if ed > 10000:
                    # printing not in order 
                    #print("not aligned printing aroudn line",line_i,line)
                    continue
                eds.append(ed)
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
            "del_found": del_found,
            "evicted_item_ages": eias,
            "evict_durations": eds
            }

    return res 

if __name__=="__main__":
    p = argparse.ArgumentParser()
    
    p.add_argument("--dir",type=str,required=True)
    p.add_argument("--algos",type=str,required=True)
    p.add_argument("--cache_size",type=str,required=True)
    p.add_argument("--thread",type=int,required=True)
    p.add_argument("--types",type=str,required=True,
                    help=PTYPE_HELP_MSG
            )
    p.add_argument("--line_limit",type=int,default=None)
    p.add_argument("--limit",type=int,default=None) 
    
    ap = p.parse_args()
    
    algos = sorted(ap.algos.split(",")) 
    PLOT_TYPES = set(ap.types.split(","))
    
    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES or PTYPE_EVICT_DURATION in PLOT_TYPES: 
        if PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES or PTYPE_FINAL_THPT_DATA in PLOT_TYPES:
            print("Throughput will be inaccurate if the output log also contains eviction duration or evicted item ages")
            print("exit...")
            exit(1) 

    ALL_RES = []

    for algo in algos:
        log_file_path = os.path.join(ap.dir,"{}_t{}_{}_log".format(ap.cache_size,ap.thread,algo))
        
        res_for_algo = parse(log_file_path,ap.line_limit)
        res_for_algo["label"] = algo

        ALL_RES.append(res_for_algo)
        
        if PTYPE_MR_OVER_TIME in PLOT_TYPES or PTYPE_MR_OVER_TIME_THRESHOLD in PLOT_TYPES or PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES:  
            print("Time executed for {}: {}".format(algo,res_for_algo["ts_list"][-1]))
         
        if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES:
            print("Last 10 evicted item ages (retention time) for {}: {}".format(algo,res_for_algo["evicted_item_ages"][-10:]))
        
        if PTYPE_EVICT_DURATION in PLOT_TYPES:
            print("Last 10 evict duration for {}: {}".format(algo,res_for_algo["evict_durations"][-10:])) 
    
    # plot_name is for the plot file name, which will consist of what plots is ploted 
    plot_name = "{}_t{}_{}_{}".format(ap.cache_size,ap.thread,",".join(algos), "-".join(sorted(PLOT_TYPES)))
    if ap.limit:
        plot_name += "_" + str(ap.limit)

    # plot_title is for the title for each plot in the outputed pdf
    plot_title = "{}_t{}_{}".format(ap.cache_size,ap.thread,",".join(algos))
    if ap.limit:
        plot_title += "_" + str(ap.limit)

    plot(ALL_RES,
        plot_name,
        plot_title)
