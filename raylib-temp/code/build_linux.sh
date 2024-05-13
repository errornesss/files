#!/bin/bash

output="../build/main"

gcc ./*.c -o $output -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
$output
# rm $output
