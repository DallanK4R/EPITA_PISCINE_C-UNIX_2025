#!/bin/sh

while IFS= read -r line; do
    if echo "$line" | grep -qE '^[[:space:]]*$'; then
        echo "it is empty"
    elif echo "$line" | grep -qE '^[[:alpha:]]+$'; then
        echo "it is a word"
    elif echo "$line" | grep -qE '^[[:digit:]]$'; then
        echo "it is a digit"
    elif echo "$line" | grep -qE '^[[:digit:]]+$'; then
        echo "it is a number"
    elif echo "$line" | grep -qE '^[[:alnum:]]+$'; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done

exit 0
