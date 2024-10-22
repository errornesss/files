#!/bin/bash

cc="zig cc"
out="main"
incsrc="include/glad/glad.c include/stb/stb_image.c"

mkdir -p bin/
cd src/
$cc -o ../bin/$out main.c utils/*.c $incsrc -Iinclude/ -lGL -lglfw
cd ../bin
./$out
rm $out
