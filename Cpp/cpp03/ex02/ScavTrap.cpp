/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:11:48 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/21 11:31:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap: " << this->_name << " copied" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_damage = obj._damage;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}
