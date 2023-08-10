/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:33:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/10 21:09:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> d;
	Array<int> a(5);
	Array<float> b(5);
	Array<std::string> c(5);

	for (int i = 0; i < 5; i++)
	{
		a[i] = rand() % 10;
		b[i] = rand() % 10;
	}
	for (int i = 0; i < 5; i++)
	{
		c[i] = "string";
	}
	std::cout << "Array a: ";
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	std::cout << "Array b: ";
	for (int i = 0; i < 5; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	std::cout << "Array c: ";
	for (int i = 0; i < 5; i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
	std::cout << "Array d: ";
	try
	{
		for (int i = 0; i < 1; i++)
			std::cout << d[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Array a: ";
		for (int i = 0; i < 6; i++)
			std::cout << a[i] << " ";
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	return (0);
}

