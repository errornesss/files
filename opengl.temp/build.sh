#!/bin/bash

pushd() {
  command pushd "$@" > /dev/null
}
popd() {
  command popd "$@" > /dev/null
}

out="main"

mkdir -p bin/
pushd src/
gcc -o ../bin/$out *.c include/glad.c -Iinclude/ -lglfw -ldl -lGL
pushd ../bin
./$out
rm $out
