for((i=1;i<=4;i++))
do
    #这里的-f参数判断$myFile是否存在
    if [ -f "./data_local/case${i}_ans.txt" ]; then
        if diff "./data_local/case${i}_ans.txt" "./data/case${i}_ans.txt"; then
        printf "AC $i \n"
        else 
        echo "WA $i \n"
        # exit 0
        fi
    fi
done
