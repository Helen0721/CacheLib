#!/bin/bash

# Define the path to the cachesim executable
# should be in the libCacheSim/_build directory
CACHE_SIM_EXEC="./build/my_cache_1"

# Define the data path where the downloaded trace files are located
DATA_PATH="data/"

OUTPUT_FILE="data/w82_to_w106_log.txt"

# Loop through the range of $ from 80 to 106
for i in {82..106}; do
    # Define the trace file name
    TRACE_FILE="w${i}.oracleGeneral.bin.zst"

    # Run cachesim with the trace file and "1gb" as arguments
    echo "Running cachesim on ${TRACE_FILE}..."
    $CACHE_SIM_EXEC "${DATA_PATH}${TRACE_FILE}" "0" >> "${OUTPUT_FILE}"
done
