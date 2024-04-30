#!/bin/bash

output="game"

mkdir -p ../build
gcc ./*.c -o ../build/$output
# ./$output
# rm $output

