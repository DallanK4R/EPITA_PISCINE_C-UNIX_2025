#!/bin/sh

if [ $# -eq 0 ]; then
    while IFS= read -r line; do
        [ -z "$line" ] && continue
        set -- $line
        echo $(( $* ))
    done
else
    echo $(( $* ))
fi
