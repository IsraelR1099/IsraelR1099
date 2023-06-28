/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:30:46 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/28 09:56:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal constructor called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = obj._type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	*this = obj;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
