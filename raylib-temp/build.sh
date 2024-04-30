#!/bin/bash

source="main.c"
include=""
output="main"

gcc $source $include -o $output -O1 -Wall -std=c99 -Wno-missing-braces -I raylib/ -L raylib/ -lraylib -lopengl32 -lgdi32 -lwinmm
./$output
rm $output
