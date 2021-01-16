#!/bin/sh

	for((i=1; i<=5; i++))
do
	for((j=1; j<=i;j++))
do
	echo -ne "*"
done
	echo;
done

	for((f=4; f>=1; f--))
do
	for((g=1; g<=f; g++))
do
	echo -ne "*"
done
	echo
done
