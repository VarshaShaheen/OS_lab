echo "Enter the filename"
read filename
read -p "enter the word to search " word
grep -o "$word" $filename | wc -l