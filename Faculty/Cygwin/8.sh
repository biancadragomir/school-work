#!/bin/bash

fisier=sort
for fisier
	do 
		sort <$fisier | more
	done
