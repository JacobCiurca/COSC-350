#!/bin/sh
if [ "$#" -ne 1 ];
then
echo "You must enter exactly one numerical argument"
else
digit=$1
sod=0
remainder=0
while [ $digit -gt 0 ]
do
	remainder=$(( $digit % 10 ))
	digit=$(( $digit / 10 ))
	sod=$(( $sod + $remainder ))
done
	echo Sum of digit for number "$1" is $sod

fi
