# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata01.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 14:30:10 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 14:46:06 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

kata = {
		'Python': 'Guido van Rossum',
		'Ruby': 'Yukihiro Matsumoto',
		'PHP': 'Rasmus Lerdorf',
		}
if __name__ == '__main__':
	print([key for key in kata.keys()][0] + " was created by {0}".format(kata["Python"]))
	print([key for key in kata.keys()][1] + " was created by {0}".format(kata["Ruby"]))
	print([key for key in kata.keys()][2] + " was created by {0}".format(kata["PHP"]))
