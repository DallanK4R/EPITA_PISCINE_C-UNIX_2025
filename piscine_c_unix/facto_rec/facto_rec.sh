#!/bin/sh

fact() {
    if [ "$#" -ne 1 ]; then
        exit 1
    elif [ $1 -eq 1 ]; then
        echo 1
        exit 0
    elif [ $1 -eq 0 ]; then
        echo 1
        exit 0
    else
        N="$1"
        N=$((N * $(fact $(($1 - 1)))))
    fi
    echo $N
    exit 0
}

if [ $# -ne 1 ]; then
        exit 1
fi
fact $1
