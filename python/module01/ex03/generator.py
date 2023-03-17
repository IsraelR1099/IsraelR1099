# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 10:57:44 by irifarac          #+#    #+#              #
#    Updated: 2023/03/17 13:10:41 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random

def generator(text, sep = " ", option = None):
    if text.isprintable():
        words = text.split(sep)
        if option == "shuffle":
            last = len(words) - 1
            while last > 0:
                nbr = random.randint(0, last)
                copy = words[last]
                words[last] = words[nbr]
                words[nbr] = copy
                last -= 1
        elif option == "ordered":
            print("hola")
            words = sorted(words)
        for word in words:
            yield word + '\n'
    else:
        print("ERROR")

if __name__ == '__main__':
    text = "Le Lorem Ipsum est simplement du faux texte."
    new = text.split()
    for i in generator(text, sep=" ", option="ordered"):
        print(i, end='')
    txt = generator(text, sep = " ", option = "shuffle")
