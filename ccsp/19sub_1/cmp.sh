for((i=1;i<=79;i++))
do
    #这里的-f参数判断$myFile是否存在
    if [ -f ./data/$i.ans2 ]; then
        if diff ./data/$i.ans2 ./data/$i.ans; then
        printf "AC $i \n"
        else 
        echo "WA $i \n"
        # exit 0
        fi
    fi
done
