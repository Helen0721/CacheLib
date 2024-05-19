#!/bin/bash

prefix="/disk/CacheLib/examples/my_cache_1/data/w"
suffix=".oracleGeneral.bin.zst"
trace_paths=()
names=()

for i in {81..106}; do
	trace_path="$prefix$i$suffix"
	trace_paths+=("$trace_path")
	names+=("w$i")
done


# Loop through the range of $ from 80 to 106
for i in {0..25}; do
    # Define the trace file name
    TRACE_FILE=${trace_paths[i]}
    NAME=${names[i]}

    echo "$TRACE_FILE"
    echo "$NAME"

    python3 generate_output.py --tracepath="$TRACE_FILE" --name="$NAME"

done
