#!/usr/bin/bash

path=$1;

num_dirs=`find $path -type d | wc -l`

num_regular=`find $path -type f | wc -l`

echo "Processed all the files from <"$path">."
echo "There were "$num_dirs" directories."
echo "There were "$num_regular" regular files."
