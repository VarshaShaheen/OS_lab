#!/bin/bash

read -p "enter the number of tearms" n
num1=0
num2=1
sum=0
n=$(($n - 1))
echo "0"
for ((i=0;i<$n;i++));
do
        sum=$(($num1 + $num2))
        num1=$num2
        num2=$sum
        echo "$sum";
done