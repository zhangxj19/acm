#!/usr/bin/env bash
echo "sh gen.sh [filename, filename.cpp]"
f=$1
f=${f%.*}
cp ../main.cpp $f.cpp
open \in
open o
open $f.cpp

if [ -f ".cpp" ]
then
rm .cpp
fi