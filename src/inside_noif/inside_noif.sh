#!/bin/sh
[ $# -ne 1 ] && echo "Sorry, expected 1 argument but $# were passed" && exit 1
[ -f $1 ] && { 
	cat $1 && exit 0
} || {
	printf "%s:\n\tis not a valid file\n" $1 && exit 2
}
