#!/bin/bash

read -p "Enter the string" word
rev=$( echo "$word" | rev)
if [[ $rev == $word ]]
then
        echo "palindrome"
else
        echo "not palindrome"
fi