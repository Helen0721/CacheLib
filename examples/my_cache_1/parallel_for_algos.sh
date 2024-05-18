#!/bin/bash

# Define the fixed arguments
MAX_REQS=1000000
CACHE_SIZE="1GB"
plot_size_script="plot_hr_size.py"

# List of data paths

prefix="/disk/CacheLib/examples/my_cache_1/data/w"
suffix=".oracleGeneral.bin.zst"
trace_paths=()
names=()

for i in {80..106}; do
	trace_path="$prefix$i$suffix"
	trace_paths+=("$trace_path")
	names+=("w$i")
done

# Export variables so they can be used by GNU Parallel
export MAX_REQS
export CACHE_SIZE

# Function to run the compiled C++ program
run_my_cache() {
    local data_path="$1"
    build/my_cache_TinyLFU "$data_path" "$MAX_REQS" "$CACHE_SIZE"
}

run_plot_hr_size(){
    local trace_path="$1"
    local name="$2"
    python3 plot_hr_size.py --tracepath="$trace_path" --name="$name" 
}

print_data_path(){
   local data_path="$1"
   echo "$data_path"
}

# Export the function for GNU Parallel
export -f run_my_cache
export -f print_data_path
export -f run_plot_hr_size

# Use GNU Parallel to run the program with each data path
#parallel -j0 --eta run_my_cache ::: "${data_paths[@]}"
#parallel print_data_path ::: "${trace_paths[@]}"
parallel -j0 --eta --link run_plot_hr_size ::: "${trace_paths[@]}" ::: "${names[@]}"

#printf '%s\n' "${trace_paths[@]}"
#printf '%s\n' "${names[@]}"

