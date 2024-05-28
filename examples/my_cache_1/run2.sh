#!/bin/bash

trace_paths=()
names=()


if [ "$1" == "Ws" ]; then
	prefix="/disk/CacheLib-M24/examples/my_cache_1/data/w"
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

num_traces=${#trace_paths[@]}

# Loop through the range of $ from 80 to 106
for (( i=0; i<num_traces; i++ )); do
    # Define the trace file name
    TRACE_FILE=${trace_paths[i]}
    NAME=${names[i]}

    echo "running $TRACE_FILE with name $NAME and rebalancing strategy $3"
    
    python3 generate_output.py --tracepath="$TRACE_FILE" --name="$NAME" --suffix="$3" --cache_size="$4"

done

