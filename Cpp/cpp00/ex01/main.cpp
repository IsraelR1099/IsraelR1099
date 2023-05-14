/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:28:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/14 20:15:22 by irifarac         ###   ########.fr       */
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
			book.setContact();
		else if (line == "SEARCH")
		{
			book.getContact();
			book.search();
		}
		std::cout << "> " << std::flush;
		std::cin >> line;
	}
	return (0);
}
