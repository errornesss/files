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
$cc -o ../bin/$out main.c utils/*.c include/*.c -Iinclude/ -lglfw -lGL
pushd ../bin
./$out
rm $out
