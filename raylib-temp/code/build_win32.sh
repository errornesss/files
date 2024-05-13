#!/bin/bash

output="../build/main"

gcc ./*.c -o $output -O1 -Wall -std=c99 -Wno-missing-braces -I raylib/ -L raylib/ -lraylib -lopengl32 -lgdi32 -lwinmm
$output
# rm $output
