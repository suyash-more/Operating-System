#!/bin/sh

# searching string pattern in using test keyword 

if [ $# -eq 0 ] ; then
echo "Enter the string to be searched: \c" ; read -r pname
if  [ -z "$pname" ] ; then
echo "You have not entered the string" ; exit 1
fi
echo "Enter the file to be used: \c" ; read -r flname
if  [ ! -n "$flname" ] ; then
echo "You have not entered the filename" ; exit 2
fi
sh demo.sh "$pname" "$flname" 
else
sh demo.sh "$*"
fi