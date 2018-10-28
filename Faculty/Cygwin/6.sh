#!/bin/bash

if test $# -eq 0 ; then
	echo "trebe fisier"
	exit 1
else
	sort <$1
fi
