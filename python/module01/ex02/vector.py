# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 21:08:32 by irifarac          #+#    #+#              #
#    Updated: 2023/03/17 10:57:14 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Vector:
    def __init__(self, lista):
    #Row vector
        if isinstance(lista, list):
            self.values = []
            for item in lista:
                if isinstance(item, list):
                    for elem in item:
                        if isinstance(elem, float):
                            self.values.append(elem)
                            self.shape = (1, len(item))
                        else:
                            print("Number must be a float type")
                elif isinstance(item, float):
                    self.values.append(item)
        elif isinstance(lista, tuple):
            self.values = []
            for item in lista:
                for elem in item:
                    if isinstance(elem, float):
                        self.values.append(elem)
                        self.shape = (len(lista), 1)
                    else:
                        print("Number must be a float type")
    def __mul__(self, other):
        if type(other) is int:
            return Vector([a * other for a in self.values])
        elif type(other) is float:
            return Vector([a * other for a in self.values])
    def __truediv__(self, other):
        if type(other) is int:
            return Vector([a / other for a in self.values])
        elif type(other) is float:
            return Vector([a / other for a in self.values])


if __name__ == '__main__':
    lista = [2.3, 3.4, 1.2]
    lista2 = ([0.0], [1.2], [3.2], [4.1])
    lista3 = ([[2.2, 1.2, 3.2, 0.2]])
    vector_row = Vector(lista3)
    print(vector_row.values)
    print(vector_row.shape)
    vector_column = Vector(lista2)
    v1 = Vector([[0.0], [1.0], [2.0], [3.0]])
    v2 = v1 * 5
    print(v2.values)
    v2 = v2 / 5
    print(v2.values)
