# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata04.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:03:57 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 16:21:50 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

kata = (0, 4, 132.42222, 10000, 12345.67)

if __name__ == '__main__':
	print("module_" + "{:0>2d}".format(kata[0]) + ", ex_" +
	"{:0>2d}".format(kata[1]) + " : " + "{:.2f}".format(kata[2]) + ", " +
	"{:.2e}".format(kata[3]) + ", " + "{:.2e}".format(kata[4]))
