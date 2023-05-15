/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:18:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 13:39:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Bienvenido a la agenda. Ingrese uno de los comandos: " << std::endl;
	std::cout << "ADD." << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "Adios" << std::endl;
}

void	PhoneBook::ft_setContact(std::string line)
{
	std::cout << "linea es " << line << std::endl;
}

void	PhoneBook::ft_getContact(void)
{
	std::cout << "Estoy en get contatc" << std::endl;
}
