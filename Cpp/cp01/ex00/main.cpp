/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:35:34 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/11 17:12:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Winslow;

	Winslow = newZombie("Winslow");
	Winslow->announce();
	randomChump("Another zombie wants to eat your brain");
	delete(Winslow);
	return (0);
}
