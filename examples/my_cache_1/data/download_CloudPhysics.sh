#!/bin/bash

# Define the base URL
BASE_URL="https://ftp.pdl.cmu.edu/pub/datasets/twemcacheWorkload/cacheDatasets/cloudphysics/"

# Loop through the range of $ from 80 to 106
for i in {80..106}; do
    # Construct the URL for the current iteration
    FILE_URL="${BASE_URL}w${i}.oracleGeneral.bin.zst"

    # Download the file
    echo "Downloading file ${i}.oracleGeneral.bin.zst..."
    wget "$FILE_URL"
done
