#!/bin/bash

output="game"

mkdir -p ../build
gcc ./*.c -o ../build/$output -lSDL2 -lSDL2main
# ../build/$output
# rm $output

