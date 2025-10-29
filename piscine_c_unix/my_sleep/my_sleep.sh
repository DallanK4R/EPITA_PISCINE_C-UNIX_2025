#!/bin/sh
while true; do
	if [ $SECONDS -eq $1 ]; then
		break
	fi
done
