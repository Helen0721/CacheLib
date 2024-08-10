#!/bin/bash

i=0
if [ -z  "$1"  ]; then
	echo "no output file directory"
	exit
fi

for file in $1/*.txt; do
  	if [[ $file =~ LruTailAge\.txt$ || $file =~ FreeMem\.txt$ || $file =~ MarginalHits\.txt$ || $file =~ HitsPerSlab\.txt$ ]]; then
		#echo "no change:  $file"
		i+=1
	else
		echo "old: $file"
		base_filename="${file:0:-4}"
		new_filename="${base_filename}_default.txt"

		echo "$new_filename"
		mv "$file" "$new_filename"
	fi
done

