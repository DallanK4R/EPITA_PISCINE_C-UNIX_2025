#!/bin/sh

[ $# -ne 2 ] && exit 1
[ ! -f "$1" ] && exit 1
[ "$(wc -l < "$1")" -lt "$2" ] && exit 1
[ "$2" -lt 0 ] && exit 1
if [ $1 -ge 0 ] 2>dev/null ; then
    exit 1
fi

line=$(head -n "$2" "$1" | tail -n 1)
col2=$(printf "%s" "$line" | cut -d';' -f2)
col3=$(printf "%s" "$line" | cut -d';' -f3)

[ -z "$col2" ] || [ -z "$col3" ] && exit 1
printf "%s is %s\n" "$col2" "$col3"
exit 0
