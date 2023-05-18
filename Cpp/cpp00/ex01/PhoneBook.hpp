/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:17:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/18 20:15:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>

class	Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		unsigned int	phone_number;
		std::string		dark_secret;
};

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	ft_setContact(std::string line);
		void	ft_getContact();
	private:
		Contact	contacts[8];
};
#endif
