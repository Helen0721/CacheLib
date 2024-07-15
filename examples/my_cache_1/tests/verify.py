import argparse
import subprocess


run_path = "build/testSieve"
uniform_obj_size = 1000000


section_start = "CacheAllocator.h-insertInMMContainer...after inserting...Inspecting Free List:"
section_end = "CacheAlloator.h-insertInMMContainer...done inspecting."

def run_one_trace(trace,obj_size):
    run_args = [run_path, str(obj_size), trace]

    p = subprocess.run(run_args,stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if p.returncode != 0: 
        logger.warning("testSieve may have crashed with segfault")
        print("return code: ", p.returncode)
        return
    
    stderr_str = p.stderr.decode("utf-8") 
    if stderr_str != "":
        logger.warning(stderr_str)
     
    stdout_str = p.stdout.decode("utf-8").split("\n")
 
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

            while line!=section_end: 
                # q,0x7f9327000000. prev: null. next:null, visited: 0
                if "Hand is null" in line:
                    res[nth_add]["Hand"] = None
                    break
                else:  
                    k = line.split(",")[0]  
                    if "Hand" in line:
                        res[nth_add]["Hand"] = k
                    visited = str(line.split("visited: ")[-1][0])

                    if visited not in ("0","1"):
                        print("incorrect parsing for visited bit on request", nth_add)
                        while i <= j: 
                            print(stdout_str[i])
                            i += 1
                        print("line for visited bit:",line)
                        return

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



if __name__=="__main__":
    
    p = argparse.ArgumentParser()
    
    p.add_argument("--traces",type=str,required=True)
    p.add_argument("--ans",type=str,required=True)
    
    p.add_argument("--out",type=str,default=None)
    p.add_argument("--obj_sizes",type=int,default=None)

    ap = p.parse_args()

    traces = ap.traces.split("-")
    answers = ap.ans.split("-") 
     
    assert len(traces) == len(answers)
    num_tests = len(traces)

    if ap.obj_sizes: 
        obj_sizes = ap.obj_sizes.split(",")
    else:
        obj_sizes = [uniform_obj_size for _ in range(num_tests)]


    for i in range(num_tests):
        trace,ans = traces[i],answers[i]
        
        print("Checking trace",i+1,end="...")
        all_res,last_res = run_one_trace(trace,obj_sizes[i])
        check_one_trace(last_res,ans)
        print("passed")

