#!/bin/zsh
for var in $@
do
	mv $var "$var.map"
done
