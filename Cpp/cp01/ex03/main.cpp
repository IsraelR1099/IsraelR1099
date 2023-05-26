/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:29:14 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/26 13:57:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int	main(void)
{
	Weapon		test;
	const std::string	&a_ref = test.getType();

	test.setType("hola");
	std::cout << "memoria es " << &a_ref << std::endl;
	std::cout << "valor es " << a_ref << std::endl;
	return (0);
}
