
a=$1
a=${a%.*}

b=$2
b=${b%.*}

while true; do
    ./r > input
    ./$a < input > o.$a
    ./$b < input > o.$b
    diff o.$a o.$b
    if [ $? -ne 0 ] ; then break; fi
done