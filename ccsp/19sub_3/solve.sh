# for((i=1;i<=79;i++))
# for((i=1;i<=20;i++))
# for((i=21;i<=30;i++))
# for((i=31;i<=42;i++))
for((i=43;i<=54;i++))
# for((i=54;i<=54;i++))
# for((i=79;i<=79;i++))
do
	# ./19sub_1 < ./data/$i.in > ./data/$i.ans2 & 
	./test < ./data/$i.in > ./data/$i.ans2 & 
done
