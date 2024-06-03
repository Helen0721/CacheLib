#!/bin/bash

i=0
#|| $file=="*FreeMem.txt" || $file=="*MarginalHits.txt" || $file=="*HitsPerSlab.txt" 
for file in *.txt; do
  	if [[ $file =~ LruTailAge\.txt$ || $file =~ FreeMem\.txt$ || $file =~ MarginalHits\.txt$ || $file =~ HitsPerSlab\.txt$ ]]; then
		#echo "$file"
		i+=1
	else
		echo "$file"
		base_filename="${file:0:-4}"
		new_filename="${base_filename}_default.txt"

		echo "$new_filename"
		mv "$file" "$new_filename"
	fi
done

