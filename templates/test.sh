#!/usr/bin/env bash
a=$1
a=${a%.*}

echo "$a"

./r > input
./$a < input

# ./test.sh $a
