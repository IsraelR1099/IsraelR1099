# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whois.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:03:30 by irifarac          #+#    #+#              #
#    Updated: 2023/03/13 12:59:13 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def isdigit(n):
    try:
        int(n)
        return True
    except:
        return False

if __name__ == '__main__':
    arguments = len(sys.argv)
    if (arguments == 2):
        if (isdigit(sys.argv[1])):
            if (int(sys.argv[1]) % 2) == 0 and int(sys.argv[1]) != 0:
                print("I'm Even.")
            elif (int(sys.argv[1]) % 2) != 0:
                print("I'm Odd.")
            elif (int(sys.argv[1]) == 0):
                print("I'm Zero")
        else:
            print("is not a number")
    elif (arguments > 2):
        print("more than one argument are provided")
    else:
        print("too few arguments")
