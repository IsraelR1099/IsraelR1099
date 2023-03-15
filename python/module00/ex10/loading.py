# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loading.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:48:28 by irifarac          #+#    #+#              #
#    Updated: 2023/03/15 18:37:58 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
import sys

def     ft_progress2(numbers):
    total = len(numbers)
    start = time.time()
    bar = 30
    eta = start - start

    for i in numbers:
        percent = 100.0*i/total
        yield i
        now = time.time()
        if i == 1:
            now = time.time()
            eta = (now - start) * total
        elapsed = now - start
        sys.stdout.write('\r')
        sys.stdout.write("ETA: {:.2f}s [{:>3}%] [{:{}}] {}/{} | elapsed time {:.2f}s ".format(eta, int(percent),
        '='*int(percent/(100.0/bar)), bar, i, total, elapsed))
        sys.stdout.flush()


if __name__ == '__main__':
    listy = range(1000)
    ret = 0
    for elem in ft_progress2(listy):
        ret += (elem + 3) % 5
        time.sleep(0.01)
    print()
    print(ret)

