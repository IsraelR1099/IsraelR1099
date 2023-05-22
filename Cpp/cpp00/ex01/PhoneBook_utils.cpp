/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:39:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/22 10:00:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	ft_is_nbr(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static bool	isValidString(const std::string &str)
{
	int	i;
	int	len;
	int	counter;

	i = 0;
	counter = 0;
	len = str.length();
	while (str[i])
	{
		if (isdigit(str[i]))
			return (false);
		if (std::isspace(str[i]))
			counter++;
		i++;
	}
	if (counter == len)
		return (false);
	return (!str.empty());
}

std::string	ft_first_name(void)
{
	std::string	new_line = "";

	std::cout << "First name: ";
	std::getline(std::cin, new_line);
	while (!isValidString(new_line))
	{
		std::cout << "Parametro no valido, ingresar un valor nuevo." <<	std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "First name: ";
		std::getline(std::cin, new_line);
	}
	return (new_line);
}

std::string	ft_last_name(void)
{
	std::string	new_line;

	std::cout << "Last name: ";
	std::getline(std::cin, new_line);
	while (!isValidString(new_line))
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Last name: ";
		std::getline(std::cin, new_line);
	}
	return (new_line);
}

std::string	ft_nickname(void)
{
	std::string	new_line;

	std::cout << "Nickname: ";
	std::getline(std::cin, new_line);
	while (!isValidString(new_line))
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Nickname: ";
		std::getline(std::cin, new_line);
	}
	return (new_line);
}

unsigned int	ft_phone_number(void)
{
	std::string	number;
	int			ret;

	std::cout << "Phone number: ";
	std::getline(std::cin, number);
	while (number.empty() || !ft_is_nbr(number))
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Phone number: " << std::flush;
		std::getline(std::cin, number);
	}
	ret = atoi(number.c_str());
	return (ret);
}

std::string	ft_secret(void)
{
	std::string	new_line;

	std::cout << "Dark secret: ";
	std::getline(std::cin, new_line);
	while (!isValidString(new_line))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Dark secret: ";
		std::getline(std::cin >> std::ws, new_line);
	}
	return (new_line);
}
