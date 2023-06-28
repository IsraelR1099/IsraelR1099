/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:34:36 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/28 09:58:42 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CCat.hpp"

CCat::CCat(void)
{
	std::cout << "CCat constructor called" << std::endl;
	this->_type = "CCat";
	this->_brain = new Brain();
}

CCat::CCat(const CCat &obj) : AAnimal(obj)
{
	std::cout << "CCat copy constructor called" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
}

CCat::~CCat(void)
{
	std::cout << "CCat destructor called" << std::endl;
	delete this->_brain;
}

CCat	&CCat::operator=(const CCat &obj)
{
	std::cout << "CCat assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	this->_brain = obj._brain;
	return (*this);
}

void	CCat::makeSound(void) const
{
	std::cout << "Meowwwwwww" << std::endl;
}

std::string	CCat::getType(void) const
{
	return (this->_type);
}
