#!/bin/bash

source="main.c"
output="../build/game"

mkdir -p ../build
gcc $source -o $output -I sdl/include -L sdl/lib -lmingw32 -lSDL2main -lSDL2
# ./$output
# rm $output

