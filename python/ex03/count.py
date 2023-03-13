# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:01:35 by irifarac          #+#    #+#              #
#    Updated: 2023/03/13 13:47:04 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def test_analyzer(str2):
    res = isinstance(str2, str)
    if (res == False):
        print("argument is not a string")
        return False
    elif (res != False):
        lower = 0
        upper = 0
        for i in str2:
            if (i.islower()):
                lower += 1
            else:
                upper += 1
    print(res)
    print("lower es:", lower)
    print(f"{upper} {hola}")

if __name__ == '__main__':
    var = "holaA"
    test_analyzer(var)
