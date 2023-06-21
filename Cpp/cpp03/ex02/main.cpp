/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:30:20 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/21 11:40:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	test1("first Clap");
	ScavTrap	stest1("first Scav");
	FragTrap	ftest1("first Frag");

	test1.attack("Attack clap");
	test1.takeDamage(3);
	test1.beRepaired(3);

	stest1.attack("Scav attack");
	stest1.takeDamage(3);
	stest1.beRepaired(3);
	stest1.guardGate();

	ftest1.attack("Frag attack");
	ftest1.takeDamage(8);
	ftest1.beRepaired(7);
	ftest1.highFivesGuys();
	return (0);
}
