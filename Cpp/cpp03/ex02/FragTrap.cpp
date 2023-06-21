/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/21 11:45:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(FragTrap const &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap: " << this->_name << " copied" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);

	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_damage = obj._damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap high fives" << std::endl;
}
