#!/bin/bash

trace_paths=()
names=()
rebs=()

if [ "$1" == "Ws" ]; then
	prefix="data/w"
	suffix=".oracleGeneral.bin.zst"
	for i in {80..106}; do
		trace_path="$prefix$i$suffix"
		trace_paths+=("$trace_path")
		names+=("w$i")
	done
else
	trace_paths+=("$1")	
	names+=("$2")	
fi

if [ -z "$3" ]; then 
	echo "No specified algos"
	exit
fi

if [ -z "$4" ]; then 
	echo "No specified reb. strategy"
	exit
fi

if [ "$4" == "all" ]; then
	rebs+=("FreeMem")
	rebs+=("default")
	rebs+=("LruTailAge")
	rebs+=("MarginalHits")
	rebs+=("HitsPerSlab")
else
	IFS=","
	read -ra array <<< "$4"
	for reb in ${array[@]}; do 
		rebs+=("$reb")
	done	
fi

if [ -z "$5" ]; then 
	echo "No specified reb. params"
	exit
fi

if [ -z "$6" ]; then 
	echo "No output folder"
	exit
fi

num_traces=${#trace_paths[@]}
num_rebs=${#rebs[@]}



# Loop through the range of $ from 80 to 106
for (( i=0; i<num_rebs; i++)); do
	REB=${rebs[i]}

	for (( j=0; j<num_traces; j++ )); do
    		# Define the trace file name
    		TRACE_FILE=${trace_paths[j]}
    		NAME=${names[j]}

		python3 generate_output.py --tracepath="$TRACE_FILE" --name="$NAME" --algos="$3" --reb="$REB" --rebParams="$5" --outputdir="$6" --cache_size="$7"		

	done
done

