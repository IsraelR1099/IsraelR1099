/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:53:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/08 20:23:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void)
{
	int	random;

	std::srand(std::time(NULL));
	random = std::rand() % 3;
	if (random == 1)
		return (new A);
	else if (random == 2)
		return (new B);
	else
		return (new C);
}

//Using dynamic_cast with pointers allows you to check whether the cast is
//valid without throwing an exception. If the cast is not valid, the result is
//a null pointer.
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "Unknown type" << std::endl;
}

//When we use dynamic_cast with references, if the cast is not valid, it throws an exception
void	identify(Base &p)
{
		try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cerr << "Unknown type" << std::endl;
}

int	main(void)
{
	Base *test = generate();

	std::cout << "Identify by pointer: ";
	identify(test);
	std::cout << "Identify by reference: ";
	identify(*test);
	delete test;
	return (0);
}
