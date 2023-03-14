# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 20:53:51 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 13:52:58 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def     isdigit(n):
    try:
        int(n)
        return (True)
    except:
        return (False)

def     operations(nbr, nbr2):
    '''Usage: python3 operations.py <number1> <number2>
        Example:
                python3 operations.py 10 3'''
    number = int(nbr)
    number2 = int(nbr2)
    print("Sum: {0}".format(number + number2))
    print("Difference: {0}".format(number - number2))
    print("Product: {0}".format(number * number2))
    if (number2 != 0):
        print("Quotient: {0}".format(number / number2))
        print("Remainder: {0}".format(number % number2))
    else:
        print("Quotient: ERROR (division by zero)")
        print("Remainder: ERROR (modulo by zero)")

if __name__ == '__main__':
    arguments = len(sys.argv)
    if (arguments == 3 and isdigit(sys.argv[1]) and isdigit(sys.argv[2])):
        operations(sys.argv[1], sys.argv[2])
    elif (arguments > 3):
        print("AssertionError: too many arguments")
    elif (arguments < 3):
        print(operations.__doc__)
    else:
        print("AssertionError: only integers")
