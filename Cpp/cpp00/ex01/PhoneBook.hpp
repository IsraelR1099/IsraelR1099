/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:17:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 13:33:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	ft_setContact(std::string line);
		void	ft_getContact();
};
#endif
