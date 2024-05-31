#!/bin/bash

names=()

if [[ -z "$1" ]]; then
	echo "name is empty"
	exit
fi
if [[ -z "$2" ]]; then
	echo "output folder is empty"
	exit
fi



if ["$1"=="w"]; then
	for i in {80..106}; do
		names+=("w$i")
	done
else 
	names+=("$1")
fi

num_traces=${#names[@]}

# Loop through the range of $ from 80 to 106
for (( i=0; i<num_traces; i++ )); do
    NAME=${names[i]}
    echo "$NAME"

    python3 plot_mr_size.py --name="$NAME" --folder="$2"
    python3 plot_mr_time.py --name="$NAME" --cache_size="all" --folder="$2"

done
