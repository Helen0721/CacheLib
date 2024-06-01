#!/bin/bash

trace_paths=()
names=()
suffixes=()

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

if [ "$3" == "all" ]; then
	suffixes+=("FreeMem")
	suffixes+=("")
	suffixes+=("LruTailAge")
	suffixes+=("MarginalHits")
	suffixes+=("HitsPerSlab")
else
	suffixes+=("$3")	
fi

if [ -z "$4" ]; then 
	echo "No output folder"
	exit
fi


num_traces=${#trace_paths[@]}
num_suffixes=${#suffixes[@]}

# Loop through the range of $ from 80 to 106
for (( i=0; i<num_suffixes; i++)); do
	SUFFIX=${suffixes[i]}

	for (( j=0; j<num_traces; j++ )); do
    		# Define the trace file name
    		TRACE_FILE=${trace_paths[j]}
    		NAME=${names[j]}
 		
		echo "$SUFFIX, $TRACE_FILE, $NAME"
    		python3 generate_output.py --tracepath="$TRACE_FILE" --name="$NAME" --suffix="$SUFFIX" --folder="$4" --cache_size="$5" 
	done
done	
