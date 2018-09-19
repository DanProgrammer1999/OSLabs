#!/bin/bash

a=0

while [ $a -lt 10 ]
do
    number=$(tail -n 1 test.txt)
    echo $((number + 1)) >> test.txt 
    a=$((a + 1))
done
