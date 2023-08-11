/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:23:05 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/11 10:07:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "Testing with int array" << std::endl;
	int intArray[5] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << "Testing with string array" << std::endl;
	std::string stringArray[5] = {"Hello", "World", "I", "Am", "Here"};
	iter(stringArray, 5, print);
	std::cout << std::endl;

	std::cout << "Testing with float array" << std::endl;
	float floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(floatArray, 5, print);
	std::cout << std::endl;

	std::cout << "Testing with double array" << std::endl;
	double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, print);
	std::cout << std::endl;
	return (0);
}
