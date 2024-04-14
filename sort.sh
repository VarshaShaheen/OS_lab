#!/bin/bash

echo "Enter the array elements:"
read -a array
read -p "Enter the order 1:ascending 2:descending: " order

if [[ $order == 1 ]]; then
    arr2=($(for i in "${array[@]}"; do echo "$i"; done | sort -n))
    echo "Sorted in ascending order: ${arr2[@]}"
else
    arr2=($(for i in "${array[@]}"; do echo "$i"; done | sort -n -r))
    echo "Sorted in descending order: ${arr2[@]}"
fi
