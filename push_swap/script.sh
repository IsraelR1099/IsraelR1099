#!/bin/bash

#gcc -Wall -Wextra -Werror ft_errors.c ft_ways_sort.c ft_find.c ft_rules.c ft_sort.c ft_utils.c main.c -o push_swap -L../Libft/ -lft -g
#chmod +x push_swap

for (( j=2; j<119; j++))
do
	./permutation | sed "$j!d" >> info.txt
done

while read line; do
	./push_swap $line
	echo $line
	filesize=$( ./push_swap $line | wc -l ) 
	if [ "$((filesize-1))" -gt 12 ];
	then
		echo -e "\033[0;31mProblem\033[0m"
	
	elif [ "$((filesize-1))" -lt 12 ];
	then
		echo -e "\033[0;32mNo problem: $((filesize-1))\033[0m"
	fi
done < info.txt
