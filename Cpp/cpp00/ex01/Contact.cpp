/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:36:27 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/23 17:36:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::ft_set(std::string name, std::string last, std::string nick,
unsigned int number, std::string dark, int i)
{
	first_name = name;
	last_name = last;
	nickname = nick;
	phone_number = number;
	dark_secret = dark;
	index = i;
}

void	Contact::ft_get(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Dark secret: " << dark_secret << std::endl;
}

std::string	Contact::ft_getFirstName(void)
{
	return (first_name);
}

std::string	Contact::ft_getLastName(void)
{
	return (last_name);
}

std::string	Contact::ft_getNickName(void)
{
	return (nickname);
}

unsigned int	Contact::ft_getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::ft_getDarkSecret(void)
{
	return (dark_secret);
}
