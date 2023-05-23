/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:28:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/23 20:23:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

int	main(void)
{
	PhoneBook	book;
	size_t		i;
	std::string	line = "";

	i = 0;
	while (line != "EXIT")
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
		{
			if (std::cin.eof())
			{
				std::cout << "Ctrl + d was detected" << std::endl;
				std::cin.clear();
				break ;
			}
		}
		if (line == "ADD")
		{
			book.ft_setContact(line, i);
			i++;
		}
		else if (line == "SEARCH")
		{
			book.ft_getContact();
		}
		line.clear();
	}
	return (0);
}
