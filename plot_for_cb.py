import os
import sys
from matplotlib.backends.backend_pdf import PdfPages
import re
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import argparse
import gc

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

PTYPE_EVICT_ITEM_AGE_LOG = "eia_log"
PTYPE_EVICT_DURATION_LOG = "ed_log"


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
    
    
    if not os.path.isdir(plot_folder):
        os.mkdir(plot_folder) 

    plot_fname = os.path.join(ap.dir,plot_folder,plot_name + ".pdf")
    #plot_fname = os.path.join(plot_folder,"test.pdf")
    pp = PdfPages(plot_fname)
    
    # -----------------------plotting the final average miss ratio-----------------------
    
    labels = [res["label"] for res in all_res]    
    
    if PTYPE_FINAL_MR in PLOT_TYPES:
        plt.figure(figsize=(6,4))
        
        final_hrs = [res["final_hr"] for res in all_res]
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
	
        hr_lists = [res["hr_list"] for res in all_res]
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
        hr_lists = [res["hr_list"] for res in all_res] 
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

        AC_lists = [res["AC_list"] for res in all_res]
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
        
        ops_lists = [res["ops_list"] for res in all_res]
        ts_lists = [res["ts_list"] for res in all_res]
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

    
    # -----------------------plotting the evicted item age over time and average eia-----------------------
    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES:
        print("PTYPE:",PTYPE_EVICTED_ITEM_AGE)

        evicted_item_ages = [res["evicted_item_ages"] for res in ALL_RES] 
        num_subplots = len(evicted_item_ages)
        fig, axs = plt.subplots(num_subplots,figsize=(5, 5)) 
        
        avg_eias = []

        for i in range(num_subplots):
            print("plotting for label:",labels[i])
            eia_list_or_path = evicted_item_ages[i]
            if isinstance(eia_list_or_path,str):
                eia_list = []
                with open(eia_list_or_path,"r") as eia_log_f:
                    for line in eia_log_f:
                        eia_list.append(int(line))
                        del line
            else:
                eia_list = eia_list_or_path
                assert eia_list == EIAs[i]
            
            gc.collect()

            num_eviction_list = [i for i in range(1,len(eia_list)+1)] 
            axs[i].plot(num_eviction_list,eia_list,color=colors[i])
            axs[i].set_xlabel("Number of Evictions",fontsize=8) 
            axs[i].set_title("Evicted Item Ages (in sec)-" + labels[i],fontsize=8)
            axs[i].grid(axis="y", linestyle="--")
         
            axs[i].tick_params(axis="x", labelsize=10)
            axs[i].tick_params(axis="y", labelsize=10)

            avg_eias.append(sum(eia_list) / len(eia_list))

            del eia_list
            gc.collect()

        plt.tight_layout(pad=1.0)
        pp.savefig()
        plt.close()
        
        plt.figure() 
        plt.barh(labels,avg_eias,color=colors[:len(labels)])
        plt.xlabel("Average Evicted Item Age (in sec)",fontsize=10)
        plt.ylabel("Eviction Algorithms",fontsize=8)
        plt.yticks(fontsize=10)
        plt.tight_layout(pad=1.0)
        pp.savefig()
        plt.close()

    
    # -----------------------plotting the evicted item age over time and bar plot for counts-----------------------
    if PTYPE_EVICT_DURATION in PLOT_TYPES:
        
        print("PTYPE:",PTYPE_EVICT_DURATION)
        
        evict_durations = [res["evict_durations"] for res in ALL_RES]
        
        all_cnts = []
        ed_cnt_buckets = [100,200,300]
        label_for_ed_cnts = ["[0~100) ns","[100,200) ms", "[200,300) ns", "beyond 300 ns"]

        ed_line_fig = plt.figure()
        num_lines = len(evict_durations)
        for i in range(num_lines): 
            ed_list_or_path = evict_durations[i]
            if isinstance(ed_list_or_path,str):
                ed_list = []
                with open(ed_list_or_path,"r") as ed_log_f:
                    for line in ed_log_f:
                        ed_list.append(int(line))
                        del line
            else:
                ed_list = ed_list_or_path
                assert ed_list == EDs[i]
            
            gc.collect()

            num_eviction_list = [i for i in range(1,len(ed_list)+1)] 
            plt.plot(num_eviction_list,ed_list,label=labels[i],color=colors[i])
            
            cnts = [0 for _ in range(len(label_for_ed_cnts))]
            
            for ed in ed_list:
                if ed < ed_cnt_buckets[0]: cnts[0] += 1
                elif ed < ed_cnt_buckets[1]: cnts[1] += 1
                elif ed < ed_cnt_buckets[2]: cnts[2] += 1 
                else: cnts[3] += 1
                
                del ed

            all_cnts.append(cnts)
    
            del ed_list,num_eviction_list
            gc.collect()

	
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
        
        del ed_line_fig
        gc.collect()

        ed_bar_fig = plt.figure()

        num_subplots = len(label_for_ed_cnts)
        fig, axs = plt.subplots(num_subplots,figsize=(8, 8))        
        
        for i in range(num_subplots):
            cnts_for_bucket = [cnt_for_algo[i] for cnt_for_algo in all_cnts] 
            axs[i].barh(labels,cnts_for_bucket,color=colors)
            axs[i].set_xlabel("Counts",fontsize=8) 
            axs[i].set_title("Evict Duration {}".format(label_for_ed_cnts[i]),fontsize=8) 
        
        plt.tight_layout(pad=1.0)
        pp.savefig(fig)
        plt.close() 
        
        del ed_bar_fig,fig,axs
        gc.collect()

    pp.close()

    print("plots saved to {}".format(plot_fname))


def parse_line(line,res):
    if "n_iters" in line:
        res["sieve_n_iters"] += 1
        return

        
    if PTYPE_MR_OVER_TIME in PLOT_TYPES:
        hr_time_m = re.search(REGEX_Time_HR,line)
        if hr_time_m: 
            ops = float(hr_time_m.group('ops')[:-1]) * (10**6)
            hit_ratio = float(hr_time_m.group('hit_ratio')) * 0.01
            
            res["ops_list"].append(ops)
            res["hr_list"].append(hit_ratio)
            res["ts_list"].append(time)
            res["time"] += 1
            return 
                
    if PTYPE_FINAL_MR in PLOT_TYPES:
        final_hr_m = re.search(REGEX_Final_HR,line)
        if final_hr_m:
            res["final_hr"] = float(final_hr_m.group('hit_ratio')) * 0.01 

            return

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
             
            res["AC_list"].append(AC)
            return


    if PTYPE_FINAL_THPT_DATA in PLOT_TYPES:

        get_m = re.search(REGEX_GET,line)
        if get_m:
            res["get_rate"] = int(get_m.group("get_rate").replace(",",""))
            res["get_success"] = float(get_m.group("get_success")) * 0.01
            return
        
        set_m = re.search(REGEX_SET,line)
        if set_m:
            res["set_rate"] = int(set_m.group("set_rate").replace(",",""))
            res["set_success"] = float(set_m.group("set_success")) * 0.01
            return

        del_m = re.search(REGEX_DEL,line)
        if del_m:
            res["del_rate"] = int(del_m.group("del_rate").replace(",",""))
            res["del_found"] = float(del_m.group("del_found")) * 0.01
            return
        
    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES:
        eia_m = re.match(REGEX_EVICTED_ITEM_AGE,line)
        if eia_m:
            eia = int(eia_m.group("evicted_item_age"))
            if eia > 5000:
                return
            res["eias"].append(eia) 
            return
        
    if PTYPE_EVICT_DURATION in PLOT_TYPES: 
        ed_m = re.match(REGEX_EVICT_DURATION,line)
        if ed_m:  
            ed = int(ed_m.group("evict_duration")) 
            if ed > 1000:
                return
            res["eds"].append(ed)
            return


def parse(f_path,line_limit):
    
    print("parsing for",f_path)

    f = open(f_path,"r")

    time = 1
    line_i = -1
    hr_list,AC_list,ops_list,ts_list,eias,eds = [],[],[],[],[],[]
    final_hr,get_rate,get_success,set_rate,set_success,del_rate,del_found,sieve_n_iters =-1,-1,-1,-1,-1,-1,-1,0
    
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
            "evict_durations": eds,
            "sieve_n_iters": sieve_n_iters
            }

    for line in f:
        line_i += 1
        if line_limit and line_i > line_limit: break

        parse_line(res,line)

        del(line)

    if "sieve" in f_path:
        print("Sieve-number of times Sieve moves hand_ back to tail",sieve_n_iters)
    
    if PTYPE_EVICT_DURATION in PLOT_TYPES and len(eds) > 2000000:
        # we save the result to a separate file to avoid overloading the memory
        ed_log_path = os.path.join(ap.dir,"{}_t{}_{}_ed_log_{}".format(ap.cache_size,ap.thread,algo,2000000))
        with open(ed_log_path,"w") as ed_log_f:
            ed_log_f.writelines(f"{number}\n" for number in eds) 
        del eds
        gc.collect()
        eds = ed_log_path

        print("Evict duration log saved to",eds,"ed list deleted")
    
    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES and len(eds) > 2000000:
        eia_log_path = os.path.join(ap.dir,"{}_t{}_{}_eia_log_{}".format(ap.cache_size,ap.thread,algo,2000000))
        with open(eia_log_path,"w") as eia_log_f:
            eia_log_f.writelines(f"{number}\n" for number in eias) 
        del eias
        gc.collect()
        
        eias = eia_log_path
        print("Evicted Item Age log saved to",eias,"eia list deleted")

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
    
    f.close()  

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
    p.add_argument("--parsed_logs",type=str,default=None)
    
    ap = p.parse_args()
    
    algos = sorted(ap.algos.split(",")) 
    PLOT_TYPES = set(ap.types.split(","))

    if ap.parsed_logs:
        parsed_logs = ap.parsed_logs.split(",")
    else:
        parsed_logs = []

    if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES or PTYPE_EVICT_DURATION in PLOT_TYPES: 
        if PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES or PTYPE_FINAL_THPT_DATA in PLOT_TYPES:
            print("Throughput will be inaccurate if the output log also contains eviction duration or evicted item ages")
            print("exit...")
            exit(1) 

    ALL_RES = []
    
    EIAs = []
    EDs = []
    
    parse_line_limit = ap.line_limit

    for algo in algos:
    
        if PTYPE_EVICT_ITEM_AGE_LOG in parsed_logs or PTYPE_EVICT_DURATION_LOG in parsed_logs:
            res_for_algo = dict()
            res_for_algo["evicted_item_ages"] = os.path.join(ap.dir,"{}_t{}_{}_eia_log".format(ap.cache_size,ap.thread,algo))
            res_for_algo["evict_durations"] = os.path.join(ap.dir,"{}_t{}_{}_ed_log".format(ap.cache_size,ap.thread,algo))
            res_for_algo["label"] = algo
            ALL_RES.append(res_for_algo)
            
            continue

        print()
        log_file_path = os.path.join(ap.dir,"{}_t{}_{}_log".format(ap.cache_size,ap.thread,algo))
        
        res_for_algo = parse(log_file_path,parse_line_limit)
        res_for_algo["label"] = algo

        ALL_RES.append(res_for_algo) 

        if PTYPE_MR_OVER_TIME in PLOT_TYPES or PTYPE_MR_OVER_TIME_THRESHOLD in PLOT_TYPES or PTYPE_NUM_OPS_OVER_TIME in PLOT_TYPES:  
            print("Time executed for {}: {}".format(algo,res_for_algo["ts_list"][-1]))
         
        if PTYPE_EVICTED_ITEM_AGE in PLOT_TYPES: 
            #print("max evicted item ages:",sorted(res_for_algo["evicted_item_ages"][-5:])) 
            EIAs.append(res_for_algo["evicted_item_ages"])

        if PTYPE_EVICT_DURATION in PLOT_TYPES: 
            #print("max evict duration:",sorted(res_for_algo["evict_durations"][-5:]))
            EDs.append(res_for_algo["evict_durations"])
    
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
