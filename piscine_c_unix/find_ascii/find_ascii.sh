#!/bin/sh

dir=$1
[ -z "$dir" ] && exit 0

for p in "$dir"/* "$dir"/.*; do
    [ "$p" = "$dir/." ] && continue
    [ "$p" = "$dir/.." ] && continue
    [ -e "$p" ] || continue
    file "$p"
done | grep 'ASCII'

