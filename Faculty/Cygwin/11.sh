#!/bin/bash

i=0;

while [ $# -gt 0 ]; do
	
	i=`expr $i + 1`;
	nr=`expr $i % 8`
	if [ $nr -eq 0 ]; then 
		echo "$1"
	fi
	shift
done

