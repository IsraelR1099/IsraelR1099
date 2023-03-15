# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    guess.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 10:49:27 by irifarac          #+#    #+#              #
#    Updated: 2023/03/15 11:47:11 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random

def     guess(number):
    '''This is an interactive guessing game!
You have to enter a number between 1 and 99 to find out the secret number.
Type exit to end  the game.
Good luck!'''
    i = 1
    print(guess.__doc__)
    while True:
        print("What's your guess between 1 and 99?")
        try:
            nbr_guess = (input())
            if nbr_guess == 'exit':
                print("Goodbye!")
                return
                sys.exit(1)
            nbr_guess = int(nbr_guess)
        except:
            print("That's not a number.")
            continue
        if (nbr_guess < number):
            print("Too low!")
        elif (nbr_guess > number):
            print("Too high!")
        elif (nbr_guess == number):
            break
        i += 1
    if i == 1:
        if number == 42:
            print("The answer to the ultimate question of life, the universe and everything is 42.")
        print("Congratulations, you got it on your first try!")
    else:
        print("Congratulations, you've got it!")
        print("You won in {0} attempts!".format(i))


if __name__ == '__main__':
    number = random.randint(1, 99)
    guess(number)
