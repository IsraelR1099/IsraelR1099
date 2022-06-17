#!/bin/bash

x = 1

while [ var=$(./a.out | sed '$x!d')]
do
	./push_swap var
	x=$(( $x + 1))
done
