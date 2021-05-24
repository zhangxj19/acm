for n in {3..10}
do
    echo "n = $n"
    ./data $n 50 50 > "in"
    ./2021a3 < "in"
done