#!/bin/bash

cc="zig cc"
out="main"

mkdir -p bin/
cd src/
$cc *.c -o ../bin/$out
cd ../bin
./$out
rm $out
