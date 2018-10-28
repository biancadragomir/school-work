#!/bin/bash

read -p "introduce the nr: " nr

nr=`expr $nr + 1`

echo $nr

nr1=`expr $nr \* $nr`
echo $nr1
