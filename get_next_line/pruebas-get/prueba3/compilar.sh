#!bin/bash
echo -n "Elegir buffer size = "
read -e size

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c main_get_next_line.c && ./a.out
