# !/usr/bin/bash
filenames=(A B C D E F G)

echo "sh gen.sh dirname"
f=$1
f=${f%.*}

mkdir $f
cd $f
echo dirname = $f

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