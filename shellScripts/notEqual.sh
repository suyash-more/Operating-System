#!/bin/sh

# Checks number of arguments > 2 and if so checks its pattern in the given file

if test $# –ne 2; then
 	   echo "You did not enter 2 arguments" 
else
 	   grep "$1" "$2" || echo "$1 not found in $2"
fi
