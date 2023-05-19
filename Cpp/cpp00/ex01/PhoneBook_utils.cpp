/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:39:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/19 13:41:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	ft_is_string(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

std::string	ft_first_name(void)
{
	std::string	new_line;

	std::cout << "First name: " << std::flush;
/*	std::getline(std::cin >> std::ws, new_line);
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "First name: " << std::flush;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin >> std::ws, new_line);
	}*/
	std::cin >> new_line;
	if (new_line.empty())
		std::cout << "line es " << new_line << std::endl;
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "First name: " << std::flush;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> new_line;
	}
	return (new_line);
}

std::string	ft_last_name(void)
{
	std::string	new_line;

	std::cout << "Last name: " << std::flush;
/*	std::getline(std::cin, new_line);
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Last name: " << std::flush;
		std::getline(std::cin >> std::ws, new_line);
	}*/
	std::cin >> new_line;
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Last name: " << std::flush;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> new_line;
	}
	return (new_line);
}

std::string	ft_nickname(void)
{
	std::string	new_line;

	std::cout << "Nickname: " << std::flush;
	std::getline(std::cin >> std::ws, new_line);
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Nickname: " << std::flush;
		std::getline(std::cin, new_line);
	}
	return (new_line);
}

unsigned int	ft_phone_number(void)
{
	std::string	number;
	int			ret;

	std::cout << "Phone number: " << std::flush;
	std::getline(std::cin >> std::ws, number);
	while (number.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Phone number: " << std::flush;
		std::getline(std::cin >> std::ws, number);
	}
	ret = std::stoi(number);
	return (ret);
}

std::string	ft_secret(void)
{
	std::string	new_line;

	std::cout << "Dark secret: " << std::flush;
	std::getline(std::cin >> std::ws, new_line);
	while (!ft_is_string(new_line) || new_line.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Parametro no valido. Ingresar valor de nuevo." << std::endl;
		std::cout << "Dark secret: " << std::flush;
		std::getline(std::cin >> std::ws, new_line);
	}
	return (new_line);
}
