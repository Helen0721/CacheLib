#!/bin/bash

traces="$1"
name="$2"

trace_paths=()
names=()


if [["$traces"=="w_."]]; then
	prefix="/disk/CacheLib/examples/my_cache_1/data/w"
	suffix=".oracleGeneral.bin.zst"d
	for i in {105..106}; do
		trace_path="$prefix$i$suffix"
		trace_paths+=("$trace_path")
		names+=("w$i")
	done
else
	trace_path=file
	trace_paths+=("$trace_path")
	names+=("$name")
fi

num_traces=${#trace_paths[@]}


# Loop through the range of $ from 80 to 106
for i in {0..$num_traces-1}; do
    # Define the trace file name
    TRACE_FILE=${trace_paths[i]}
    NAME=${names[i]}

    echo "$TRACE_FILE"
    echo "$NAME"

   #python3 generate_output.py --tracepath="$TRACE_FILE" --name="$NAME"

done
