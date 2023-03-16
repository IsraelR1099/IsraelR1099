# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:00:42 by irifarac          #+#    #+#              #
#    Updated: 2023/03/16 21:03:53 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class GotCharacter:
    def __init__(self, first_name, is_alive=True):
        if isinstance(first_name, str):
            self.first_name = first_name
        else:
            print("First name must be a string")
        if isinstance(is_alive, bool):
            self.is_alive = is_alive


class Stark(GotCharacter):
    '''A class representing the Stark family. Or when bad things happen to good people.'''
    def __init__(self, first_name=None, is_alive=True):
        super().__init__(first_name=first_name, is_alive=is_alive)
        self.family_name = "Stark"
        self.house_words = "Winter is Coming"
    def print_house_words(self):
        print(self.house_words)
    def die(self):
        self.is_alive = False

if __name__ == '__main__':
    pablo = Stark("Pablo")
    print(pablo.__dict__)
    print(pablo.__doc__)
    pablo.print_house_words()
    print(pablo.first_name, pablo.is_alive)
    pablo.die()
    print(pablo.first_name, pablo.is_alive)

