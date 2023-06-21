/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:30:20 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/21 10:33:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	test1("first Clap");
	ScavTrap	stest1("first Scav");

	test1.attack("Attack clap");
	test1.takeDamage(3);
	test1.beRepaired(3);

	stest1.attack("Scav attack");
	stest1.takeDamage(3);
	stest1.beRepaired(3);
	stest1.guardGate();
	return (0);
}
