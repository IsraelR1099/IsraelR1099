/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:17:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/24 10:11:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <limits>
#include <cstdlib>
#include <iomanip>

class	Contact
{
	public:
		Contact();
		~Contact();
		void			ft_set(std::string name, std::string last, std::string nick,
						unsigned int number, std::string dark, int i);
		std::string		ft_getFirstName();
		std::string		ft_getLastName();
		std::string		ft_getNickName();
		unsigned int	ft_getPhoneNumber();
		std::string		ft_getDarkSecret();
		void			ft_get();
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		unsigned int	phone_number;
		std::string		dark_secret;
		int				index;
};

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	ft_setContact(std::string line, size_t index);
		void	ft_getContact();
		void	ft_show();
	private:
		Contact	contacts[8];
		size_t	nbr_contacts;
};

std::string		ft_first_name(void);
std::string		ft_last_name(void);
std::string		ft_nickname(void);
unsigned int	ft_phone_number(void);
std::string		ft_secret(void);
#endif
