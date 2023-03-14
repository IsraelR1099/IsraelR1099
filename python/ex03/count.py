# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:01:35 by irifarac          #+#    #+#              #
#    Updated: 2023/03/13 20:51:30 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string
import sys

def test_analyzer(str2):
    '''This functions counts the number of upper characters, lower characters, punctuation and spaces in a given text'''
    res = isinstance(str2, str)
    lower = 0
    upper = 0
    punctuation = 0
    space = 0

    if (res == False):
        print("argument is not a string")
        return False
    elif (res != False):
        for i in str2:
            if (i.islower()):
                lower += 1
            elif (i.isupper()):
                upper += 1
        for i in str2:
            if i in string.punctuation:
                punctuation +=1
        for i in str2:
            if i.isspace():
                space += 1
    print("The text contains {0} character(s)".format(len(str2)))
    print("- {0} upper letter(s)".format(upper))
    print("- {0} lower letter(s)".format(lower))
    print("- {0} punctuation mark(s)".format(punctuation))
    print("- {0} space(s)".format(space))


if __name__ == '__main__':
    arguments = len(sys.argv)
    if (arguments == 2):
        variable = sys.argv[1]
        test_analyzer(variable)
    else:
        print("Wrong number of arguments")
