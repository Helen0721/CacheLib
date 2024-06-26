import os
import glob
import sys
import itertools
from collections import defaultdict
import re
import numpy as np
import random
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.colors as mcolors
from matplotlib.lines import Line2D
import logging
import json


CACHE_SIZES = ["256MB","512MB","1GB","2GB","4GB","8GB","16GB","32GB","64GB"]
ALGOS = ["Lru","Lru2Q","TinyLFU"]
REBALANCEING_STRATEGIES = ["LruTailAge", 
                            "FreeMem", 
                            "MarginalHits", 
                            "HitsPerSlab",
                            "default"
                            ]

PWD = os.getcwd()
REGEX=r"hit ratio:(?P<hit_ratio>\d+.\d+),time:(?P<time>\d+)" 


colors=['tab:green', 'tab:red', 'tab:blue','tab:brown',
        'tab:pink','tab:olive','tab:cyan','tab:orange',
        'tab:purple','tab:grey'
        ]

markers=["o","x","d","s"]
linestyles =["-","-.", "-.", ":"]

def plot(plot_dir,plot_name,plot_title,hr_lists,cache_sizes,labels):
    COLORS =itertools.cycle(colors)
    MARKERS=itertools.cycle(markers)
    LINESTYLES = itertools.cycle(linestyles)
    
    num_lines = len(hr_lists) 
    if num_lines==0: 
        print("no plot to plot.")  
        return

    plot_fname = os.path.join(plot_dir,"reb-size-"+plot_name+"-"+plot_title+".pdf")

    pp = PdfPages(plot_fname)
    #log plot
    plt.figure()
    
    for i in range(num_lines): 
        hr_list = hr_lists[i] 
        mr_list = [1-float(i) for i in hr_list] 
        print(mr_list)
        plt.plot(cache_sizes,mr_list,
                color=next(COLORS),
                label=labels[i],
                marker=next(MARKERS),
                linestyle=next(LINESTYLES)
                )

    plt.title(plot_title)
    legend = plt.legend(ncol= (num_lines // 4 if num_lines > 3 else num_lines ), 
                        loc="upper right", fontsize="6", frameon=False) 
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.grid(axis="y", linestyle="--") 
    plt.xlabel("Size") 
    plt.ylabel("Miss Ratio") 
    pp.savefig()
    plt.close()
    pp.close()

    print("log plot saved to {}".format(plot_fname))


def parse_for_size(file):
    
    stdout_str = []
    with open(file,"r") as f:
        stdout_str = f.read().split("\n")
    
    line = stdout_str[-3]
    m = re.search(REGEX,line)

    if not m:
        print("incorrect output file format")
        print(line)
        return -1
    
    final_hr = m.group("hit_ratio")

    print("miss ratio:",1-float(final_hr))
    return final_hr



def handle():
    hr_lists,labels = [],[]
    for (i,algo) in enumerate(algos):
        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
            
            if rebalance_strategy=="MarginalHits" and algo!="Lru2Q": continue

            hr_lists.append([])
            labels.append(rebalance_strategy + "-" + algo)



def plot_for_best(cache_sizes, best_mrs,best_rebParams,labels, plot_folder,plot_name,plot_title): 
    plot_fname = os.path.join(plot_folder,plot_name+".pdf")
    pp = PdfPages(plot_fname)
    
    n_categories = len(cache_sizes)
    n_bars = len(best_mrs[0])
    # Colors for each bar group
    colors = plt.cm.tab20(np.linspace(0, 1, n_bars))[::-1]   

    bar_width = 0.2
    text_x_pos = 0.003
    
    # plot for individual cache size
    for (i,cache_size) in enumerate(cache_sizes):
        print("plotting for cache size {}".format(cache_size))
        fig = plt.figure(figsize=(15,8))
        plt.clf()

        mrs_for_cs = best_mrs[i]
        rebParams_for_cs = best_rebParams[i]
        bars = plt.barh(labels,mrs_for_cs,color=colors[-1],height = bar_width)

        print(mrs_for_cs)
        print(rebParams_for_cs)
        print(bars)

        text_x_pos -= 0.0003
        
        for (j,bar) in enumerate(bars):
            width = bar.get_width()
            plt.text(text_x_pos, bar.get_y() + bar.get_height()+0.2,rebParams_for_cs[j],fontsize=13,color='dimgrey') 


        plt.title(plot_title+"-"+cache_size,fontsize=20)
        plt.xlabel('Miss Ratios',fontsize=20)
        plt.ylabel("Eviction Algorithm-Slab Rebalancing Algorithm",fontsize=20)
        plt.xticks(fontsize=25)
        plt.yticks(fontsize=25)

        pp.savefig(fig,bbox_inches='tight')
        plt.close()


    print("plotting for all cache sizes")
    bar_width = 0.04  # Decrease width to give more space between bars
    bar_spacing = 0.02
    category_spacing = 0.9  # Decrease this value to reduce space between categories

    index = np.arange(n_categories) * category_spacing
    
    fig, ax = plt.subplots(figsize=(16, 29))
    
    for i in range(n_bars):
        # Calculate the position for each bar within the group
        bar_pos = index + (i - n_bars / 2) * (bar_width + bar_spacing)
        data = [row[i] for row in best_mrs]
        ax.barh(bar_pos, data, bar_width, label=labels[i], color=colors[i])

    ax.margins(y=0.01)
    plt.title(plot_title+"-all",fontsize=20)
    plt.xlabel('miss ratios',fontsize=30)
    plt.ylabel('Cache Sizes',fontsize=30)
    plt.yticks(index, cache_sizes, fontsize=20)
    plt.xticks(fontsize=30)
    legend = plt.legend( 
            fontsize="30", frameon=False,borderaxespad=0.,
            bbox_to_anchor=(1, 1), loc='upper right')
    frame = legend.get_frame() 
    frame.set_facecolor("0.9") 
    frame.set_edgecolor("0.9")
    plt.tight_layout(pad=1.0)
    pp.savefig(fig)
    plt.close()

    pp.close()
    print("best rebalancing parameters config plot saved to {}".format(plot_fname))

    return


def handle_best():

    reb_sep_s = "-" * 100
    algo_sep_s = "*" * 100 + "\n"
    mr_s = "Final Miss Ratio"
    rebParams_s = "rebParams"


    best_mrs = []
    best_rebParams = []
    labels = []



    for (i, cache_size) in enumerate(cache_sizes):
        labels_for_cs = []
        best_mrs_for_cs = []
        best_rebParams_for_cs = []

        RES_FOR_CS = ALL_RES[cache_size]

        for (j,rebalance_strategy) in enumerate(rebalance_strategies): 

            RES_FOR_REB = RES_FOR_CS[rebalance_strategy] 

            for (k,algo) in enumerate(algos): 
                if rebalance_strategy == "MarginalHits" and algo!="Lru2Q": continue 
            
                best_res_dict = RES_FOR_REB[algo]["best_result"]
 
                for (file_name, best_res) in best_res_dict.items():
                    try:
                        best_mr = best_res[mr_s]
                        if rebalance_strategy == "default": 
                            best_params = "None"
                        else:
                            best_params = best_res[rebParams_s]
                    except:
                        print(best_res_dict)
                        exit(1)

                best_mrs_for_cs.append(best_mr)
                best_rebParams_for_cs.append(best_params)
                if rebalance_strategy=="default":
                    labels_for_cs.append(algo)
                else:
                    labels_for_cs.append(algo+"-"+rebalance_strategy)
 
        best_mrs.append(best_mrs_for_cs)
        labels.append(labels_for_cs)
        best_rebParams.append(best_rebParams_for_cs)

    plot_folder = ap.plot_folder
    plot_name = "best-reb-config"
    plot_title = plot_name
    labels = labels[0]
    plot_for_best(cache_sizes, best_mrs,best_rebParams,labels, plot_folder,plot_name,plot_title)


def plot_for_defaultVsbest(cache_sizes, dnb_mrs, dnb_params, labels, plot_folder,plot_name,plot_title):
    plot_fname = os.path.join(plot_folder,plot_name+".pdf")
    pp = PdfPages(plot_fname)

    n_categories = len(labels)
    n_bars = len(dnb_mrs[0])
    colors = plt.cm.tab20(np.linspace(0, 1, n_bars+1))  
    
    bar_width = 0.07
    bar_spacing = 0.1
    category_spacing = 0.37 
    text_x_pos = 0.052
   
    indices = []
    for i in range(n_categories):
        if i >= n_categories - 3:
            indices.append(i * category_spacing - (i - (n_categories-3)) * (bar_spacing + bar_width))
        else:
            indices.append(i * category_spacing)
    indices = np.array(indices)


    true_legend_labels = ["default","best","unspecified"]
 
    # plot for individual cache size
    for (i,cache_size) in enumerate(cache_sizes):
        print("plotting for cache size {}".format(cache_size))
        plt.clf()
        
        params_fontsize = 19
        fig, ax = plt.subplots(figsize=(25,19))
        #else:
        #    params_fontsize = 13
        #    fig, ax = plt.subplots(figsize=(18,15))

        default_mrs = [mrs[0] for mrs in dnb_mrs[i]]
        default_params = [params[0] for params in dnb_params[i]]

        best_mrs = [mrs[1] for mrs in dnb_mrs[i]]
        best_params = [params[1] for params in dnb_params[i]]
        
        # default bars
        default_bars = []
        for j in range(len(default_mrs)):
            if j >= (n_categories-3):
                color = colors[-1]
                default_bar = ax.barh(indices[j], default_mrs[j], 
                    bar_width, label = "unspecified",color=color)
            else:
                color = colors[0]                         
                default_bar = ax.barh(indices[j], default_mrs[j], 
                    bar_width, label = "default",color=color)

            default_bars.append(default_bar)

        for (j,d_bar) in enumerate(default_bars):
            if "-" in labels[j]:
                for rec in d_bar:
                    ax.text(text_x_pos,rec.get_y() + rec.get_height()+0.01,
                            "default:"+default_params[j],fontsize=params_fontsize,color='dimgrey') 
               
        # best bars
        best_bars = []
        for j in range(len(best_mrs)-3):
            best_bar=ax.barh(indices[j] + bar_width + bar_spacing, best_mrs[j], 
                    bar_width, label = "best", color = colors[1])
            best_bars.append(best_bar)
        
        for k in range(len(best_params)-3):
            b_bar = best_bars[k]
            for rec in b_bar:
                ax.text(text_x_pos,rec.get_y() + rec.get_height()+0.01,
                        "best:"+ best_params[k],fontsize=params_fontsize,color='dimgrey') 

        if ap.name=="wiki2019t":
            x_left_lim = 0.4
        else:
            x_left_lim = min(min(default_mrs),min(best_mrs))-0.01

        ax.set_xlim(left=x_left_lim)
        ax.set_xlabel("Miss Ratios",fontsize=25)  
        ax.set_ylabel("Eviction Algorithm - Slab Rebalancing Algorithm",
                        fontsize=25)
        ax.set_yticks(indices + bar_width / 2)
        ax.set_yticklabels(labels,fontsize=30)
        ax.tick_params(axis='x', which='major', labelsize=35)
        ax.tick_params(axis='y', which='major', labelsize=30) 
        ax.margins(y=0.01)
 
        lh,_ = ax.get_legend_handles_labels()
        true_legend_handles = [] 
        true_legend_handles.append(lh[9])
        true_legend_handles.append(lh[-1]) 
        true_legend_handles.append(lh[10])

  
        legend = ax.legend(true_legend_handles,true_legend_labels, 
            fontsize="35", frameon=False,borderaxespad=0.,
            bbox_to_anchor=(1, 1), loc='upper right')

        plt.tight_layout(pad=2.0)

        ax.set_title(plot_title + "-" + cache_size,fontsize=18)

        pp.savefig(fig)
        plt.close(fig)

    pp.close()
    print("default vs best config plot saved to {}".format(plot_fname))

    return



def handle_bestVsdefault():
    mr_s = "Final Miss Ratio"
    rebParams_s = "rebParams"

    default_config_dict = {
            "LruTailAge": "tailAgeDifferenceRatio:0.25,minTailAgeDifference:100,minSlabs:1,numSlabsFreeMem:3;slabProjectionLength:1",
            "HitsPerSlab": "minDiff:100,diffRatio:0.1,minSlabs:1,numSlabsFreeMem:3,min\maxLruTailAge:0",
            "FreeMem": "minSlabs:1,numFreeSlabs:3,maxUnAllocatedSlabs:1000",
            "MarginalHits": "movingAveParam:0.3,minSlabs:1,maxFreeMemSlabs:1"
            }
    
    default_config_compressed = {
            "MarginalHits": "1,0.3,1,1"
            }
           
    dnb_mrs = []
    labels = []
    dnb_params = []


    for (i, cache_size) in enumerate(cache_sizes):
        RES_FOR_CS = ALL_RES[cache_size]

        labels_for_cs = []
        dnb_mrs_for_cs = []
        dnb_params_for_cs = []

        for (j,rebalance_strategy) in enumerate(rebalance_strategies):
             
            RES_FOR_REB = RES_FOR_CS[rebalance_strategy]
            
            for (k,algo) in enumerate(algos): 
                if rebalance_strategy == "MarginalHits" and (algo!="Lru2Q" and algo!="default"): continue 

                RES_FOR_ALGO = RES_FOR_REB[algo]

                default_f_name = os.path.join(ap.output_folder,rebalance_strategy,
                        "{}_{}_{}_{}_default".format(
                    ap.name,algo,cache_size,rebalance_strategy))
                
                if rebalance_strategy == "default": 
                        default_params = "None"
                else:
                    default_params = default_config_dict[rebalance_strategy]
                

                try:
                    default_res = RES_FOR_ALGO[default_f_name] 
                except:
                    default_file = default_f_name = os.path.join(ap.output_folder,rebalance_strategy,
                        "{}_{}_{}_{}_{}".format(
                    ap.name,algo,cache_size,rebalance_strategy,default_config_compressed[rebalance_strategy]))
                    default_res = RES_FOR_ALGO[default_f_name]
                
                default_mr = default_res[mr_s]

                best_res_= RES_FOR_ALGO["best_result"]

                for (file_name, best_res) in best_res_.items():
                    try:
                        best_mr = best_res[mr_s]
                        if rebalance_strategy == "default": 
                            best_params = "None"
                        else:
                            best_params = best_res[rebParams_s]
                    except:
                        print(best_res_dict)
                        exit(1)

                dnb_mrs_for_cs.append([default_mr,best_mr])
                dnb_params_for_cs.append([default_params, best_params])
                if rebalance_strategy == "default":
                    labels_for_cs.append(algo)
                else:
                    labels_for_cs.append("{}-{}".format(algo,rebalance_strategy))

            dnb_mrs.append(dnb_mrs_for_cs)
            dnb_params.append(dnb_params_for_cs)
            labels.append(labels_for_cs)


    plot_folder = ap.plot_folder
    plot_name = "Reb-Default_vs_Best"
    plot_title = plot_name
    labels = labels[0]

    plot_for_defaultVsbest(cache_sizes, dnb_mrs,dnb_params,labels, plot_folder,plot_name,plot_title)



if __name__ == "__main__": 
    import argparse
    p = argparse.ArgumentParser()
    p.add_argument("--output_folder",type=str,required=True)
    p.add_argument("--plot_folder",type=str,required=True)
    p.add_argument("--json_file",type=str,required=True)
    p.add_argument("--name",type=str,required=True)
    p.add_argument("--plot_type",type=str,required=True)
    
    p.add_argument("--cache_sizes",type=str,default="all")
    p.add_argument("--rebalance_strategies",type=str,default="all")
    p.add_argument("--algos",type=str,default="all")

    ap = p.parse_args()  
   
    # given a trace, x axis is the cache size. y axis is the miss ratio.  
    # we want [Lru, Lru2Q, TinyLFU] * [4 rebalancing strategy]

    if (ap.cache_sizes=="all"):
        cache_sizes = CACHE_SIZES
        if ap.name == "metakvt1":
            cache_sizes.remove("64GB")
            cache_sizes.remove("32GB")
        elif ap.name == "w06":
            cache_sizes.remove("64GB")
    else:
        cache_sizes = ap.cache_sizes.split(",")


    if (ap.rebalance_strategies=="all"):
        rebalance_strategies = REBALANCEING_STRATEGIES
    else:
        rebalance_strategies = ap.rebalance_strategies.split(",")


    if ap.algos=="all":
        algos = ALGOS
    else:
        algos = ap.algos.split(",")

    with open(ap.json_file,"r") as jf:
        ALL_RES = json.load(jf)

    if ap.plot_type == "bestReb":
        handle_best()
    elif ap.plot_type == "defaultVsbest":
        handle_bestVsdefault()
