/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:31:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/24 13:41:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>

int	main(int counter, char **str)
{
	if (counter == 2)
	{
		std::cout << "type es : " << typeid(str[1]).name() << std::endl;
		int	test = static_cast<int>(str[1][0]);
		std::cout << test << std::endl;
		std::cout << "la primera string es " << str[1] << std::endl;
	}
	return (0);
}
