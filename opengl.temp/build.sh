#!/bin/bash

pushd() {
  command pushd "$@" > /dev/null
}
popd() {
  command popd "$@" > /dev/null
}

cc="zig cc"
out="main"
incsrc="include/glad/glad.c include/stb/stb_image.c"

mkdir -p bin/
pushd src/
$cc -o ../bin/$out main.c utils/*.c $incsrc -Iinclude/ -lGL -lglfw
pushd ../bin
./$out
rm $out
