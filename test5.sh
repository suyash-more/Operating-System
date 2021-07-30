#! /bin/bash
if  [ -n "$pname" -a -n "$flname" ] ; then
demo.sh "$pname" "$flname"
else
echo " At least one input was null string " ; exit 1
fi