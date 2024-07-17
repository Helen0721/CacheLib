import argparse
import subprocess
import re

run_path = "build/testSieve"
uniform_obj_size = 1000000

section_start = "CacheAllocator.h-insertInMMContainer...after inserting...Inspecting Free List:"
insert_end = "CacheAlloator.h-insertInMMContainer...done inspecting."
record_end = "CacheAlloator.h-recordAccessInMMContainer, done inspecting."
section_end = "done inspecting." 

TRACES = ["qweqwert",
        "aabbc",
        "aabbcb",
        "abcefg",
        "aaaa",
        "rxuaug",
        "ebnex",
        "ebnexl",
        "ebnexlkmom",
        "ebnexlkmomx", 
        "incvchvhf",
        ]

ANSWERS = ["t:0;e;t:0,r:0,e:0",
        "c:1;None;c:0,b:1,a:1",
        "b:1;None;c:0,b:1,a:1",
        "g:0;e;g:0,f:0,e:0",
        "a:1;None;a:1",
        "g:0;u;g:0,a:0,u:1",
        "x:0;n;x:0,n:0,e:0",
        "l:0;x;l:0,x:0,e:0",
        "m:1;m;o:0,m:1,e:0",
        "x:0;None;x:0,m:0,e:0",
        "f:0;v;f:0,h:0,v:0"
        ]

libCacheSim_s = "Sieve.c-evicted req: "
CacheLib_s = "SieveList-remove...removed "

libCacheSim_Hand_s = "hand: " 
CacheLib_Hand_s = "hand: "

#1665453729,0x7f45a83a6e68, visited: 1. prev: 1666654178, 0x7f45a83c02b0, next: 1668757991, 0x7f45a838da20
REGEX_Hand = r'hand: (?P<id>\d+),.*visited:\s*(?P<visited>\d)'


def run_one_trace(trace,obj_size,open_mode="w"):
    run_args = [run_path, str(obj_size), trace]

    p = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if p.returncode != 0: 
        logger.warning("testSieve may have crashed with segfault")
        print("return code: ", p.returncode)
        return
    
    stderr_str = p.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)
     
    stdout_str = p.stdout.decode("utf-8")

    with open(output_file,open_mode) as f:
        f.write("trace: " + trace + "\n")
        f.write(stdout_str)
        f.write("\n")

    stdout_str = stdout_str.split("\n")
 

    res = dict()    

    nth_add = -1
    i = 0


    while i < len(stdout_str):
        line = stdout_str[i] 
        
        if "key: " in line: 
            nth_add += 1
            res[nth_add] = dict()

            key = line.split("key: ")[-1]
            res[nth_add]["Key"] = key 
            
            operations = stdout_str[i+1]
            if "recordAccess" in operations:
                res[nth_add]["Hit"] = "1"
            else:
                res[nth_add]["Hit"] = "0"
            
            CacheState = []

            j = i + 2
            line = stdout_str[j]

            while section_end not in line:  
                if "Hand is null" in line:
                    res[nth_add]["Hand"] = None        
                else:  
                    # ex. q,0x7f9327000000. prev: null. next:null, visited: 0
                    # ex. e,0x7f49be24c5f0. prev: r, 0x7f49be000000. next:null, visited: 0 . Hand
                    k = line.split(",")[0] 

                    visited = str(line.split("visited: ")[-1][0])
                    if visited not in ("0","1"):
                        print("incorrect parsing for visited bit on request", nth_add+1)
                        while i <= j: 
                            print(stdout_str[i])
                            i += 1
                        print("line for visited bit:",line)
                        return
                    
                    if "Hand" in line:
                        res[nth_add]["Hand"] = k

                    CacheState.append((k,visited))

                j += 1
                line = stdout_str[j]
            
            res[nth_add]["State"] = CacheState
        
            i = j 
        else:
            i += 1
        
    return res,res[nth_add]

def check_one_trace(res,ans):
    # t:0;e;t:0,r:0,e:0
    # {'Key': 't', 'Hit': '1', 'Hand': 'e', 'State': [('t', '0'), ('r', '0'), ('e', '0')]}
    ans = ans.split(";")

    ref = dict()
    try:
        assert(len(ans) == 3)
    except:
        print(res)
        print(ans)
        exit(1)

    for (i,parts) in enumerate(ans):  
        if i==0: 
            parts_ = parts.split(":")
            ref["Key"] = parts_[0]
            ref["Hit"] = parts_[1] 
        elif i==2:
            parts_ = parts.split(",")
            ref["State"] = []
            for part in parts_:
                ref["State"].append(part.split(":"))
        else:
            ref["Hand"] = parts if parts!=None else None
    try: 
        assert(ref["Key"] == res["Key"])
        assert(ref["Hit"] == ref["Hit"])
        assert(ref["Hand"] == ref["Hand"])
        assert(len(ref["State"]) == len(res["State"]))
    except:
        print("ref: ",ref)
        print("res: ",res)
        exit(1)

    for i in range(len(ref["State"])):
        ref_k,ref_v = ref["State"][i]
        sol_k,sol_v = res["State"][i]
        try:
            assert(ref_k == sol_k and ref_v == sol_v)
        except:
            print("ref: ",ref)
            print("res: ",res)
            exit(1)


def validate_self_def_traces():
    for i in range(num_tests):
        trace,ans = traces[i],answers[i]
        
        print("Checking trace",i+1,end="...")
        all_res,last_res = run_one_trace(trace,obj_sizes[i],open_mode="w" if i==0 else "a")
        check_one_trace(last_res,ans)
        print("passed")

def check_evicted_objs():
    print("Checking evicted objects",end="...")
    with open(ap.out,"r") as f:
        my_stdout = f.read().split("\n")

    with open(ap.ref,"r") as f:
        ref_stdout = f.read().split("\n")
    
    
    refs = []
    for line in ref_stdout:
        if libCacheSim_s not in line: continue
        parts = line.split(libCacheSim_s)
        obj = parts[-1].split("...")[0]
        refs.append(int(obj))

    mine = []
    
    
    for line in my_stdout:
        if CacheLib_s not in line: continue
        parts = line.split(CacheLib_s)
        obj = parts[-1].split("...")[0]
        mine.append(int(obj))
        
    for i in range(min(len(refs),len(mine))):
        if refs[i] != mine[i]:
            print("{}th eviction obj doesn't match.".format(i))
            print("refs...num evicted objs:",len(refs))
            print("mine...num evicted objs:",len(mine))
            print("ref:{},mine:{}".format(refs[i],mine[i]))
            exit(0)

    print("passed")



def check_hand():
    print("Checking Hand",end="...")
    with open(ap.out,"r") as f:
        my_stdout = f.read().split("\n")

    with open(ap.ref,"r") as f:
        ref_stdout = f.read().split("\n")

    refs = []
    for line in ref_stdout:
        if libCacheSim_Hand_s not in line: continue 
        
        if "null" in line: 
            refs.append((None,None))
        else:
            m = re.search(REGEX_Hand,line)
            if not m: 
                print(line)
                exit(0)
            obj = m.group("id")
            visited = m.group("visited")
            refs.append((int(obj),int(visited)))

    mine = []
    
    
    for line in my_stdout:
        if CacheLib_Hand_s not in line: continue
        
        if "null" in line: 
            mine.append((None,None))
        else:
            m = re.search(REGEX_Hand,line)
            if not m: 
                print(line)
                exit(0)
            obj = m.group("id")
            visited = m.group("visited")
            mine.append((int(obj),int(visited)))
    
    with open("ref-c","w") as f:
        for L in refs:
            f.write(str(L))
            f.write("\n")

    with open("out-c","w") as f:
        for L in mine:
            f.write(str(L))
            f.write("\n")

    for i in range(min(len(refs),len(mine))):

        if refs[i][0]!=mine[i][0] or refs[i][1]!=mine[i][1]:            
            print("{}th hand doesn't match.".format(i+1))
            print("len(refs):",len(refs))
            print("len(mine)",len(mine))
            print("ref:{},mine:{}".format(refs[i],mine[i]))
            

            exit(0)
    
    
    print("passed")


if __name__=="__main__":
    
    p = argparse.ArgumentParser()
    
    p.add_argument("--type",type=str,required=True)

    p.add_argument("--traces",type=str,default=None)
    p.add_argument("--ans",type=str,default=None) 
    p.add_argument("--out",type=str,default=None)
    p.add_argument("--ref",type=str,default=None)
    p.add_argument("--obj_sizes",type=int,default=None)

    ap = p.parse_args()

    if ap.type == "checkEvicted":
        check_evicted_objs()
    elif ap.type == "checkHand":
        check_hand()
    elif ap.type == "traces":
        if ap.traces and ap.ans:
            traces = ap.traces.split("-")
            answers = ap.ans.split("-")
        else:
            traces = TRACES
            answers = ANSWERS
     
        assert len(traces) == len(answers)
        num_tests = len(traces)
        if ap.obj_sizes: 
            obj_sizes = ap.obj_sizes.split(",")
        else:
            obj_sizes = [uniform_obj_size for _ in range(num_tests)]


    
