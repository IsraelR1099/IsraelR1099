/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:10:24 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/12 14:14:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	aggression1("first");

	aggression1.attack("hola");
	aggression1.beRepaired(-3);
	aggression1.takeDamage(2);
	return (0);
}
