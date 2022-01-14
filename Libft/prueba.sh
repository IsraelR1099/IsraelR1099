#!/bin/bash
echo -e "Los archivos usados son \033[31;1;13m$1\033[0m, \033[32;1;13m$2\033[0m y \033[36;1;13m$3\033[0m"
gcc -Wall -Wextra -Werror $1 $2 $3
./a.out
