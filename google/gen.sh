# !/usr/bin/env bash
filenames=(
1
2
3
4
)

echo "sh gen.sh [filename, filename.cpp]"
f=$1
f=${f%.*}

mkdir $f
cd $f

for filename in ${filenames[@]}; do
  if [ ! -f "./{filename}.cpp" ]; then
    cp ../main.cpp ${filename}.cpp
  fi
  if [ ! -f "./in" ]; then
    touch "./in"
  fi
done

if [ -f ".cpp" ]
then
rm .cpp
fi

rm -r ./*.dSYM