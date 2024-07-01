from tqdm import tqdm
import csv
import argparse

if __name__ ==  "__main__":
    
    p = argparse.ArgumentParser()
    p.add_argument("--input",type=str,required=True)
    p.add_argument("--output",type=str,required=True)
    p.add_argument("--input_line_num",type=int,required=True)

    ap = p.parse_args()

    RES = [["time","object","size","next_access_vtime"] ]
    input_line_num = ap.input_line_num

    with open(ap.input,"r") as csvFile:
        csvReader = csv.reader(csvFile)
        
        i = -1
        for line in tqdm(csvReader,desc="Processing",ncols=80,total=input_line_num,leave=True):
            i+=1
            if i == 0: continue
            if i > input_line_num:
                print(line)
            
            time = line[0]
            obj_id = line[1]
            op_count = line[4]
            obj_size = line[5]

            entry = [time,obj_id,obj_size,-1]

            for _ in range(int(op_count)):
                RES.append(entry)
    
    output_line_num = len(RES)
    with open(ap.output,"w") as csvFile:
        csvWriter = csv.writer(csvFile)

        for line in tqdm(RES,desc="Writing",total=output_line_num,ncols=80, leave=True):
            csvWriter.writerow(line)
