#!/bin/sh
if [ "$#" -ne 1 ];
then
echo "You must enter exactly one command line argument"
exit 1
else
n=$1
fact=$1
f=1
while [ $n -gt 1 ];
do
f=$(($f * $n))
n=$(($n - 1))
done

echo The factorial of $fact is $f
fi
exit 0
