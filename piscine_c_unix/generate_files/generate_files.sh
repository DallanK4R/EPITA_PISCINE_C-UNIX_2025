#!/bin/sh

filename=default
number=1
extension=txt

if [ $(($#%2)) -eq 1 ]; then
	exit 1
fi

cpt=$(($#/2))

for i in $( seq $cpt ); do
	if [ "$1" = "-f" ] || [ "$1" = "--filename" ]; then
		filename=$2
	elif [ "$1" = "-n" ] || [ "$1" = "--number" ]; then
		number=$2
	elif [ "$1" = "-e" ] || [ "$1" = "--extension" ]; then
		extension=$2
	else
		exit 1
	fi
	shift 2
done

for j in $( seq $number ); do
	touch -- "$filename-$j.$extension"
done
