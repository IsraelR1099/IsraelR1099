#!/bin/bash
echo -n "Introducir un nombre de archivo: ";
read -e archivo

if [ -f "$archivo"  ]
then
	echo -e "\033[32;1;13mEl archivo existe\033[0m"
	find . | grep $archivo
else
	echo -e "\033[31;1;13mEl archivo no existe\033[0m"
fi
