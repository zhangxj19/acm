for n in {1..100}; do
  ./rand > "in"
  ./C < "in" > "o1"
  ./C-BF < "in" > "o2"
  diff o1 o2 > "diffres"
  if [ "$?" != "0" ]; then
    echo "not same"
    break
  fi
done