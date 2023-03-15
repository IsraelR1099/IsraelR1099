# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata03.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:50:31 by irifarac          #+#    #+#              #
#    Updated: 2023/03/15 13:13:50 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

kata = "The right format"

if __name__ == '__main__':
	var = (kata[:42]) if len(kata) >= 42 else kata
	print("{:->42s}".format(var), end='', flush=True)
