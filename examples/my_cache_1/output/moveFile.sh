#!/bin/bash

# Define the source directory and the target directory
TARGET_DIR="$1"

# Ensure the target directory exists
mkdir -p "$TARGET_DIR"

# Move the files
#for i in $(seq 80 106); do
    # Check for files starting with the current index
    # for file in w"$i"*; do
for file in "$2"*; do
   # Move the file if it exists
   if [ -f "$file" ]; then
	   mv "$file" "$TARGET_DIR"
   fi
done
#done
