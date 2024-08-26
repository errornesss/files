#!/bin/bash

out="../build/main"

mkdir -p ../build
gcc ./*.c -o $out
$out
# rm $out
