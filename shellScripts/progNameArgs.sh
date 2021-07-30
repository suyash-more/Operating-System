#! /bin/bash

# This will show the program's name and arguments with the pattern matching in it or not

echo "Program $0 : The number of arguments provided are $# and the arguments are $*"
grep "$1" "$2"
echo "Job is over"