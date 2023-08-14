/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:45:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/14 11:11:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "--------INT----------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "-----------STRING---------" << std::endl;
	MutantStack<std::string>	v;

	v.push("hola");
	v.push("hola");
	v.push("hola");
	v.push("hola");
	MutantStack<std::string>::iterator	test = v.begin();
	MutantStack<std::string>::iterator	test2 = v.end();
	while (test != test2)
	{
		std::cout << *test << std::endl;
		++test;
	}
	return (0);
}
