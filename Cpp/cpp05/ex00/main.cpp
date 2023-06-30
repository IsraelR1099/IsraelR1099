/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:20:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/30 13:44:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main(void)
{
	Bureaucrat	test("hola", 2);
	Bureaucrat	copy(test);
	Bureaucrat	equal;
	try
	{
		Bureaucrat	test2("hola2", 1000);
	}
	catch (std::out_of_range)
	{
		std::cout << "Error out of range\n" << std::endl;
	}

	try
	{
		Bureaucrat	test3("hola3", -100);
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cout << "Exception\n" << std::endl;
	}
	std::cout << "name es: " << test.getName() << std::endl;
	std::cout << "grade es: " << test.getGrade() << std::endl;
	std::cout << "copy name es: " << copy.getName() << std::endl;
	std::cout << "copy grade es: " << copy.getGrade() << std::endl;
	std::cout << "equal name es: " << equal.getName() << std::endl;
	std::cout << "equal grade es: " << equal.getGrade() << std::endl;
	equal = test;
	std::cout << "despues equal name es: " << equal.getName() << std::endl;
	std::cout << "equal grade es: " << equal.getGrade() << std::endl;
	return (0);
}
