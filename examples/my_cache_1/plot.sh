#!/bin/bash

names=()

for i in {80..106}; do
	names+=("w$i")
done


# Loop through the range of $ from 80 to 106
for i in {0..26}; do
    NAME=${names[i]}
    echo "$NAME"

    #python3 plot_mr_size.py --name="$NAME"
    python3 plot_mr_time.py --name="$NAME" --cache_size="all"

done
