/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:12:03 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/13 21:02:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor de: " << name << " llamado" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_damage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor de: " << this->_name << " llamado" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_damage = obj._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << "His amount of energy after attacking is: " << this->_energyPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << this->_name << " is repairing itself " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	std::cout << "His amount of HP after repairing is: " << this->_hitPoints << std::endl;
	this->_energyPoints -= 1;
	std::cout << "His amount of energy after repairing is: " << this->_energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " points of damage" << std::endl;
	this->_hitPoints -= amount;
	std::cout << "His amount of HP after taking damage is: " << this->_hitPoints << std::endl;
}
