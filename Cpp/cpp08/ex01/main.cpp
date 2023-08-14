/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:35:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/14 10:59:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(-21);
	sp.addNumber(5);
	sp.addNumber(11);
	sp.addNumber(19);
	sp.addNumber(-111);
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	sp.print();
	std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span is: " << sp.longestSpan() << std::endl;

	std::cout << "---------------------" << std::endl;

	Span	sp2 = Span(20);
	for (int i = 0; i < 20; i++)
		sp2.addNumber(rand() % 100);
	sp2.print();
	std::cout << "shortest span is: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest span is: " << sp2.longestSpan() << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "---------THEIR TESTS---------" << std::endl;

	Span sp3 = Span(5);

	sp3.addNumber(6);
	sp3.addNumber(3);
	sp3.addNumber(17);
	sp3.addNumber(9);
	sp3.addNumber(11);

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "--------add Number---" << std::endl;
	Span sp4 = Span(10);
	std::vector<int> numbersToAdd;

	numbersToAdd.push_back(1);
	numbersToAdd.push_back(2);
	numbersToAdd.push_back(3);
	numbersToAdd.push_back(4);
	numbersToAdd.push_back(5);
	sp4.addNumber<std::vector<int> >(numbersToAdd.begin(), numbersToAdd.end());
	std::cout << "shortest is: " <<  sp4.shortestSpan() << std::endl;
	std::cout << "longest: " << sp4.longestSpan() << std::endl;
	sp4.print();

	std::cout << "---------------------" << std::endl;
	std::cout << "Trying to copy" << std::endl;
	Span sp5 = sp;
	sp5.print();

	std::cout << "---------------------" << std::endl;
	Span	zero = Span(2);
	zero.addNumber(0);
	zero.addNumber(0);
	std::cout << "shortest span is: " << zero.shortestSpan() << std::endl;
	std::cout << "longest span is: " << zero.longestSpan() << std::endl;
	zero.print();
	return (0);
}
