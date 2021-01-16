#!/bin/bash

echo Please enter a number between 5 and 9

read n

if(($n < 5))
then
echo Error number not between 5 and 9
	exit -1
elif(($n > 9))
then
echo Error number not between 5 and 9
	exit -1
else
	for ((i=1; i<=n; i++));
do
	for ((j=1; j<=n - i; j++));
do
	echo -n " "
done
	for ((j=1; j<=i; j++));
do
	echo -n $i " "
done
	echo
done
fi

