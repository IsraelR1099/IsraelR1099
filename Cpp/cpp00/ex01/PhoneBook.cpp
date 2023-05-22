/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:18:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/22 13:50:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Bienvenido a la agenda. Ingrese uno de los siguientes comandos: " << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
	nbr_contacts = 0;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "Adios" << std::endl;
}

void	PhoneBook::ft_setContact(std::string line, size_t index)
{
	int				i;
	std::string		read[5];
	unsigned int	number;
	Contact			new_contact;

	i = 0;
	std::cout << "Ha introducido el comando: " << line << std::endl;
	std::cout << "Introducir los datos del contacto: " << std::endl;
	while (i < 5)
	{
		if (i == 0)
			read[i] = ft_first_name();
		else if (i == 1)
			read[i] = ft_last_name();
		else if (i == 2)
			read[i] = ft_nickname();
		else if (i == 3)
			number = ft_phone_number();
		else if (i == 4)
			read[i] = ft_secret();
		i++;
	}
	if (index >= 7)
	{
		std::cout << "Indice de contacto demasiado alto, se remplaza el ultimo contacto."
			<< std::endl;
		index = 7;
	}
	new_contact.ft_set(read[0], read[1], read[2], number, read[4], index);
	contacts[index] = new_contact;
	nbr_contacts++;
	std::cout << "Contacto agregado correctamente." << std::endl;
}

void	PhoneBook::ft_getContact(void)
{
	int	index;

	if (nbr_contacts == 0)
	{
		std::cout << "No existen contactos. Agregue al menos uno" << std::endl;
		return ;
	}
	this->ft_show();
	std::cout << "Escoja el indice del contacto: ";
	std::cin >> index;
	if (index > 0 && index < 9)
	{
		index--;
		contacts[index].ft_get();
	}
	else
	{
		std::cin.clear();
		std::cout << "Indice invalido." << std::endl;
		return ;
	}
}

void	PhoneBook::ft_show(void)
{
	size_t		i;
	std::string	str;

	i = 0;
	std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
	while (i < nbr_contacts)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		if (contacts[i].ft_getFirstName().length() >= 9)
		{
			str = contacts[i].ft_getFirstName().substr(0, 9);
			std::cout << str << ".";
		}
		else
			std::cout << std::setw(10) << contacts[i].ft_getFirstName();
		std::cout << "|";
		if (contacts[i].ft_getLastName().length() >= 9)
		{
			str = contacts[i].ft_getLastName().substr(0, 9);
			std::cout << str << ".";
		}
		else
			std::cout << std::setw(10) << contacts[i].ft_getLastName();
		std::cout << "|";
		if (contacts[i].ft_getNickName().length() >= 9)
		{
			str = contacts[i].ft_getLastName().substr(0, 9);
			std::cout << str << ".";
		}
		else
			std::cout << std::setw(10) << contacts[i].ft_getNickName();
		std::cout << "|";
		std::cout << "\n";
		std::cout << "|-------------------------------------------|" << std::endl;
		i++;
	}
}
