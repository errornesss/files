#!/bin/bash

pushd() {
  command pushd "$@" > /dev/null
}
popd() {
  command popd "$@" > /dev/null
}

cc="zig cc"
out="main"

mkdir -p bin/
pushd src/
$cc -o ../bin/$out *.c utils/*.c include/glad.c -Iinclude/ -lglfw -ldl -lGL
pushd ../bin
./$out
rm $out
