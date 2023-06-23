/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:28:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/23 13:53:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal is making noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
