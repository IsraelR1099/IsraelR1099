/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:20:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/30 13:53:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Hay dos formas de capturar un valor de una clase que hereda de
//std::exception: by value catch (std::out_of_range) o by reference
//catch (const std::out_of_range &obj).
//Cuando capturamos el objeto by value estamos creando una copia de ese objeto
//y todos los cambios que se hagan quedaran dentro del bloque catch. En cambio,
//si capturamos la excepcion por referencia los cambios que hagamos quedaran
//grabados en la excepcion misma. En general es mejor capturar la excepcion por
//referencia, ya que evitamos copias innecesarias

int	main(void)
{
	Bureaucrat	test("hola", 2);
	Bureaucrat	copy(test);
	Bureaucrat	equal;
	try
	{
		Bureaucrat	test2("hola2", 1000);
	}
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Error out of range\n" << std::endl;
	}

	try
	{
		Bureaucrat	test3("hola3", -100);
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Exception\n" << std::endl;
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
