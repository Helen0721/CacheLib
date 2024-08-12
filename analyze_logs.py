import re

REGEX = r"Hit Ratio\s+(?P<hr>\d+\.\d+)%"

if __name__ == "__main__":
    import argparse

    p = argparse.ArgumentParser()
    p.add_argument("-i",type=str,required=True)
    p.add_argument("-hr",type=int,required=True)
    
    ap = p.parse_args()

    with open(ap.i,"r") as inp_f:
        stdout = inp_f.read()

    stdout = stdout.split("Welcome to OSS version of cachebench")[-1].split("\n")   

    # one minute per line
    num_lines = ap.hr * 60
    

    # 09:59:41   38908.05M ops completed. Hit Ratio  88.97% (RAM  88.97%, NVM   0.00%)
    res = []
    stdout_ = []
    for line in stdout: 
        m = re.search(REGEX,line)
        if not m:
            #print("regex not found in",line)
            continue
        hr =float(m.group("hr")) * 0.01
        res.append(hr) 
        stdout_.append(line)

    try:
        assert(len(res) > num_lines)
    except:
        print("incorrect parsing")
        print(res[-10:])

    all_res = res[:num_lines]
    all_avg_hr = sum(all_res) / len(all_res)

    last_hour_res = res[-30:]
    last_hour_avg_hr = sum(last_hour_res) / len(last_hour_res)

    print("last 5 minutes:",stdout_[:num_lines][-5:])

    print("Average hit ratio over {} hours: {}".format(ap.hr,all_avg_hr))
    print("Average hit ratio over last of {} hour: {}".format(ap.hr,last_hour_avg_hr))

