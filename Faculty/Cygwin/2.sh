#!/bin/bash

aici=`ls`
acolo=`ls $1`

echo $aici
echo $acolo

if test "$aici" = "$acolo"; then
	echo yas
	else echo nah
fi

