#!/usr/bin/env bash
echo "sh gen.sh [filename, filename.cpp]"
f=$1
f=${f%.*}

if [ ! -f "./$f.cpp" ]; then
    cp ../main.cpp ./$f.cpp
fi 
open $f.cpp

if [ ! -f "./in" ]; then
  touch "./in"
fi
open "./in"
if [ ! -f "./o" ]; then
  touch "./o"
fi
open "./o"

if [ -f ".cpp" ]
then
rm .cpp
fi
