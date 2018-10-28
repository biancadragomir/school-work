#!/bin/bash

read -p "x^2 coeff: " a
read -p "x coeff: " b
read -p "c: " c

delta=`expr $b \* $b - 4 \* $a \* $c`

#python -c 'import math; rad=`math.sqrt(4)`'

rad=$(echo "sqrt($delta)" | bc)


echo $rad
