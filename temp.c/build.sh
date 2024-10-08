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
gcc *.c -o ../bin/$out
pushd ../bin
./$out
rm $out
