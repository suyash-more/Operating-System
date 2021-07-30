#!/bin/sh

# This program will find a pattern you provide into the file you provide 

echo "Enter the pattern to be searched: "
read -r pname
echo "Enter the file to be used: " 
read -r flname
echo "Searching for $pname from file $flname"
grep "$pname" "$flname"
echo "Selected records shown above" 
