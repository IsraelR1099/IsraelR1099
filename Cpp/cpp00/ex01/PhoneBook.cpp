/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:18:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/19 13:41:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Bienvenido a la agenda. Ingrese uno de los comandos: " << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "Adios" << std::endl;
}

void	PhoneBook::ft_setContact(std::string line)
{
	int				i;
	std::string		read[4];
	//unsigned int	number;

	i = 0;
	std::cout << "Ha introducido el comando: " << line << std::endl;
	std::cout << "Introducir los datos del contacto: " << std::endl;
	while (i < 5)
	{
		if (i == 0)
			read[i] = ft_first_name();
		else if (i == 1)
			read[i] = ft_last_name();
		/*else if (i == 2)
			read[i] = ft_nickname();
		else if (i == 3)
			number = ft_phone_number();
		else if (i == 4)
			read[i] = ft_secret();*/
		i++;
	}
}

void	PhoneBook::ft_getContact(void)
{
	std::cout << "Estoy en get contact" << std::endl;
}
