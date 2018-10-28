#!/bin/bash

while [ $# -ne 0 ]; do
	if [ ! -f $1 ]; then
		echo "$1" >> file.txt
	fi
	shift
done 
