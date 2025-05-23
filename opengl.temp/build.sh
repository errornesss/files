#!/bin/bash

cc="zig cc"
out="main"
incsrc="dep/glad/glad.c dep/glfw/glfw.a dep/stb/stb_image.c"

mkdir -p bin/
# cd src/
$cc src/main.c -o bin/$out src/utils/*.c $incsrc
cd bin
./$out
rm $out
