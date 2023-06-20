/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:10:24 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/12 21:45:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	aggression1("first");
	ClapTrap	aggression2("second");
	ClapTrap	aggression3("third");
	ClapTrap	aggression4(aggression1);

	aggression1.attack("hola");
	aggression1.beRepaired(-3);
	aggression1.takeDamage(2);
	aggression2 = aggression3;
	return (0);
}
