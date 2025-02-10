#!/bin/bash

output_file="out.txt"

> "$output_file"

directories=("scenes/error" "scenes/bonus" "scenes/basic")

for dir in "${directories[@]}"; do
	for map in "$dir"/*; do
		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=.suppress_mlx_error.sup ./bin/miniRT "$map" >> "$output_file" 2>&1
	done
done

sed -i '/^$/d' "$output_file"
sed -i '/^\[uProgress:/d' "$output_file"