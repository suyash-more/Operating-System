#! /bin/bash

# illsutrating another file usage in one shell file with if else statements


if  [ -n "$pname" -a -n "$flname" ] ; then
sh demo.sh "$pname" "$flname"
else
echo " At least one input was null string " ; exit 1
fi

