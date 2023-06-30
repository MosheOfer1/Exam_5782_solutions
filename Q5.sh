#!/bin/bash

# First part
ls b* > bfiles.txt

# Second part
for ((i=1; i<=100; i++))
do
    filename="file${i}.txt"
    touch "$filename"
done
