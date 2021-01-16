#!/bin/sh
echo Please enter the full path of a directory you would like to find
read Directory
if [ ! -d "$Directory" ]; then
echo That is not a Directory! Please try again
exit 1;
else
echo Please enter a readable file to be searched for in that directory
for((i=1; i<=3; i++)); do
read File
if [ -e $Directory/"$File" ];
then
if [ ! -r $Directory/"$File" ]; 
then 
	echo File not readable
	exit 3
fi
cd $Directory
echo Please enter a word to look up
read Word
if grep -q $Word "$File"
then 
	echo $Word FOUND!
	exit 0
else
	echo $Word NOT FOUND
	exit 4
fi
else
	echo File not found
fi
done
fi
	echo File not foud after 3 attempts
	exit 2
