#!/bin/bash

a=0

while [ $a -lt 10 ]
do
    while ! ln ex2_out.txt ex2_out.txt.lock 2>/dev/null
    do
        sleep 1
    done
    number=$(tail -n 1 ex2_out.txt)
    echo $((number + 1)) >> ex2_out.txt 
    rm -f ex2_out.txt.lock

    a=$((a + 1))
done
