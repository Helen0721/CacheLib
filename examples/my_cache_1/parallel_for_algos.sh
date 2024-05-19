#!/bin/bash

# Define the fixed arguments
MAX_REQS=1000000
CACHE_SIZE="1GB"

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

CACHE_SIZES=()
CACHE_SIZES+=("256MB")
CACHE_SIZES+=("512MB")
CACHE_SIZES+=("1GB")
CACHE_SIZES+=("2GB")
CACHE_SIZES+=("4GB")
CACHE_SIZES+=("8GB")
CACHE_SIZES+=("16GB")
CACHE_SIZES+=("32GB")
CACHE_SIZES+=("64GB")


# Export variables so they can be used by GNU Parallel
export MAX_REQS
export CACHE_SIZE

# Function to run the compiled C++ program
run_my_cache_TinyLFU() {
    local data_path="$1"
    local name="$2"
    echo "$data_path"
    echo "$name"
    for cachesize in ${CACHE_SIZES[@]} ; do
	echo "$cachesize"
    	#build/my_cache_TinyLFU "$data_path" "$MAX_REQS" "$cache_size" > "output/$name_$cachesize.txt"
    done
}

run_my_cache_Lru2Q() {
    local data_path="$1"
    build/my_cache_Lru2Q "$data_path" "$MAX_REQS" "$CACHE_SIZE"  > "output/$name"
}

run_my_cache_Lru() {
    local data_path="$1"
    build/my_cache_Lru "$data_path" "$MAX_REQS" "$CACHE_SIZE" > "output/$name"
}

run_plot_hr_size(){
    local trace_path="$1"
    local name="$2"
    python3 plot_mr_size.py --tracepath="$trace_path" --name="$name" 
}

run_plot_hr_time(){
    local trace_path="$1"
    local name="$2"
    python3 plot_mr_time.py --tracepath="$trace_path" --name="$name" --cache_size="$CACHE_SIZE" 
}

print_data_path(){
   local data_path="$1"
   echo "$data_path"
}

# Export the function for GNU Parallel
export -f run_my_cache_TinyLFU
export -f print_data_path
export -f run_my_cache_Lru2Q
export -f run_my_cache_Lru
export -f run_plot_hr_size
export -f run_plot_hr_time


# Use GNU Parallel to run the program with each data path
#parallel print_data_path ::: "${trace_paths[@]}"

parallel -j0 --eta --link run_my_cache_TinyLFU ::: "${trace_paths[@]}" ::: "${names[@]}"

#parallel -j0 --eta --link run_plot_hr_size ::: "${trace_paths[@]}" ::: "${names[@]}"
#parallel -j0 --eta --link run_plot_hr_time ::: "${trace_paths[@]}" ::: "${names[@]}"

#printf '%s\n' "${trace_paths[@]}"
#printf '%s\n' "${names[@]}"

