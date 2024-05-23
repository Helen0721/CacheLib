#!/bin/bash

# Loop through the files in the directory
for file in output/wiki2019ts10_*; do
    # Check if the file matches the desired pattern
    #if [[ $file =~ wiki2019ts10_(Lru|Lru2Q|TinyLFU)_(256MB|512MB|1GB|2GB|4GB|8GB|16GB|32GB|64GB).txt ]]; then
    # Construct the new filename by appending the suffix
    base_filename="${file:0:-4}"
    echo "$base_filename"
    new_filename="${base_filename}_LruTailAge.txt"    
    echo "$new_filename"
    # Rename the file
    mv "$file" "$new_filename"    
    #fi
done

echo "Renaming completed."
