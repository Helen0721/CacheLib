#!/bin/bash

# Define the fixed arguments
MAX_REQS=1000000
CACHE_SIZE="1GB"
plot_size_script="plot_hr_size.py"

# List of data paths
data_paths=(
    "/disk/CacheLib/examples/my_cache_1/data/w90.oracleGeneral.bin.zst"
    "/disk/CacheLib/examples/my_cache_1/data/w91.oracleGeneral.bin.zst"
    "/disk/CacheLib/examples/my_cache_1/data/w92.oracleGeneral.bin.zst" 
    # Add more paths as needed
)

# Export variables so they can be used by GNU Parallel
export MAX_REQS
export CACHE_SIZE

# Function to run the compiled C++ program
run_my_cache() {
    local data_path="$1"
    build/my_cache_TinyLFU "$data_path" "$MAX_REQS" "$CACHE_SIZE"
}

run_plot_hr_size(){
    local data_path="$1"
    python3 "$plot_size_script" --tracepath="$data_path" 
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
#parallel print_data_path ::: "${data_paths[@]}"
parallel -j0 --eta run_plot_hr_size ::: "${data_paths[@]}"


