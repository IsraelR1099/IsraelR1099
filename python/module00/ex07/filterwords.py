# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 21:43:37 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 22:07:49 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def	isdigit(nbr):
	try:
		int(nbr)
		return (True)
	except:
		return (False)

def	filter_words(str1, nbr):
	lst = str1.split()
	i = 0
	while i < len(lst):
		word = len(lst[i])
		if word <= nbr:
			lst.pop(i)
			i -= 1
		i += 1
	print(lst)

if __name__ == '__main__':
	arguments = len(sys.argv)
	if (arguments == 1):
		print("ERROR")
		sys.exit(0)
	if sys.argv[1].isnumeric() == True:
		print("ERROR")
	if (arguments == 3) and isdigit(sys.argv[2]):
		filter_words(sys.argv[1], int(sys.argv[2]))
	else:
		print("ERROR")
