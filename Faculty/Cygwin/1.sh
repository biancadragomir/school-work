#!/bin/bash

while test $# -gt 0; do
	nr=$(($1%5));
	if [[ nr -eq 0 ]]; then
		echo $1
	fi
	shift
done
