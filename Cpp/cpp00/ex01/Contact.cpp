/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:36:27 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/21 21:45:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	std::cout << "Entrando en constructor contact" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Saliendo destructor contact" << std::endl;
}

void	Contact::ft_set(std::string name, std::string last, std::string nick,
unsigned int number, std::string dark)
{
	first_name = name;
	last_name = last;
	nickname = nick;
	phone_number = number;
	dark_secret = dark;
}

void	Contact::ft_get(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Dark secret: " << dark_secret << std::endl;
}

