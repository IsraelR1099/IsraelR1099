/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:52:30 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/11 21:29:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (int indice = 0; indice < 4; indice++)
	{
		std::cout << "v[" << indice << "] = " << v[indice] << std::endl;
	}
	std::vector<int>::iterator it = easyfind(v, 3);
	if (it != v.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(v, 5);
		if (it != v.end())
			std::cout << "Found: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}

