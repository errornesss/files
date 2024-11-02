#!/bin/bash

cc="zig cc"
out="main"
incsrc="head/glad/glad.c head/stb/stb_image.c"

# mkdir -p bin/
# cd src/
$cc src/main.c -o bin/$out src/utils/*.c $incsrc -lGL -lglfw
cd bin
./$out
rm $out
