# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 21:08:32 by irifarac          #+#    #+#              #
#    Updated: 2023/03/16 21:58:51 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Vector:
    def __init__(self, lista):
    #Row vector
        if isinstance(lista, list):
            self.values = []
            for item in lista:
                for elem in item:
                    print(elem)
                    if isinstance(elem, float):
                        self.values.append(elem)
                    else:
                        print("Number must be a float type")
        elif isinstance(lista, tuple):

if __name__ == '__main__':
    lista = [2.3, 3.4, 1.2]
    lista2 = ([0.0], [1.2], [3.2], [4.1])
    lista3 = ([[2.2, 1.2, 3.2, 0.2]])
    print(type(lista3))
    print(type(lista2))
    vector = Vector(lista3)
    print(vector.values)
