# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loading.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:48:28 by irifarac          #+#    #+#              #
#    Updated: 2023/03/15 13:56:24 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time

def     ft_progress(numbers):
    per = 2
    x = 0
    call = 0
    total = len(numbers)
    for number in numbers:
        call += 1
        print("[{0}%]".format((number / total * 100)), end='', flush=True)
        if number / numbers[1] == per:
            per += 2
            x += 1
            print("[{:=>{x}s}]".format("=>", x=x), end='', flush=True)
        else:
            print('', end='', flush=True)
        print("{0}/{1}".format(call, total))
        yield number

if __name__ == '__main__':
    listy = range(100)
    print(listy)
    ret = 0
    for elem in ft_progress(listy):
        ret += elem
        time.sleep(0.005)

