/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:28:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 13:48:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

int	main(void)
{
	PhoneBook	book;
	std::string	line = "";

	while (line != "EXIT")
	{
		if (line == "ADD")
			book.ft_setContact(line);
		else if (line == "SEARCH")
		{
			book.ft_getContact();
		}
		std::cout << "> " << std::flush;
		std::cin >> line;
	}
	return (0);
}
