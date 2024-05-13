#!/bin/bash

output="../build/game"

mkdir -p ../build
gcc ./*.c -o $output -lSDL2 -lSDL2main
$output
# rm $output

