#!/usr/bin/env bash
echo "sh gen.sh [filename, filename.cpp]"
f=$1
f=${f%.*}

if [ ! -f "./in" ]; then
  touch "./in"
fi


if [ ! -f "./o" ]; then
  touch "./o"
fi


if [ ! -f "./$f.cpp" ]; then
    cp ./main.cpp ./$f.cpp
fi 

# open "./in" "./o" $f.cpp
open $f.cpp


if [ -f ".cpp" ]
then
rm .cpp
fi

rm -r ./*.dSYM
python clean.py