#!/bin/bash

while [ $# -gt 0 ]; do
	if [ -r "$1" -a -x "$1" ]; then
		echo $1
	fi
	shift
done	

