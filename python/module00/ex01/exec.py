# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:24:27 by irifarac          #+#    #+#              #
#    Updated: 2023/03/13 12:02:07 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if __name__ == '__main__':
    str = ' '.join(sys.argv[1:])
    counter = len(str) - 1
    while (counter >= 0):
        if str[counter].isupper():
            print(str[counter].lower(), end="")
        elif str[counter].islower():
            print(str[counter].upper(), end="")
        else:
            print(str[counter], end="")
        counter -= 1

