#!/bin/bash

output="../build/game"

mkdir -p ../build
gcc ./*.c -o $output -I sdl/include -L sdl/lib -lSDL2main -lSDL2 -lmingw32 
$output
# rm $output

