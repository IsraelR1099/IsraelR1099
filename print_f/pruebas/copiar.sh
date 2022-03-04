#!/bin/bash

echo -n "Elegir archivo para copiar: "
read -e archivo

if [ -f "$archivo" ]
then
	cp $archivo /Users/irifarac/Ejercicios/gitIsrael/IsraelR/IsraelR1099/print_f/pruebas/
	echo -e "\033[32;1;13mArchivo copiado\033[0m"
else
	echo -e "\033[31;1;13mArchivo no copiado\033[0m"
fi
