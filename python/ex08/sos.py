# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sos.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:13:45 by irifarac          #+#    #+#              #
#    Updated: 2023/03/14 23:05:49 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

dictionary_morse = { 'A': '.-', 'B': '-...',
					'C': '-.-.', 'D': '-..',
					'E': '.', 'F': '..-.',
					'G': '--.', 'H': '....',
					'I': '..', 'J': '.---',
					'K': '-.-', 'L': '.-..',
					'M': '--', 'N': '-.',
					'O': '---', 'P': '.--.',
					'Q': '--.-', 'R': '.-.',
					'S': '...', 'T': '-',
					'U': '..-', 'V': '...-',
					'W': '.--', 'X': '-..-',
					'Y': '-.--', 'Z': '--..',
					'1': '.----', '2': '..---',
					'3': '...--', '4': '....-',
					'5': '.....', '6': '-....',
					'7': '--...', '8': '---..',
					'9': '----.', '0': '-----'}

def	encrypt(message):
	str1 = ''
	for letter in message:
		if letter != ' ':
			str1 += dictionary_morse[letter] + ' '
		else:
			str1 += '/'

	print(str1)

if __name__ == '__main__':
	encrypt(sys.argv[1].upper())
