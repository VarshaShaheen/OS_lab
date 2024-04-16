#!/bin/bash
read -p "enter the lower limit: " n1
read -p "enter the upper limit: " n2
for((i=$n1;i <= $n2;i++));
do
        limit=$((i/2))
        flag=0
        for((j=2;j <= $limit;j++));
        do
                check=$((i%j))
                if [[ $check == 0 ]]
                then
                        flag=1
                fi
        done
        if [[ $flag == 0 ]]
        then
                echo "$i"
        fi
done