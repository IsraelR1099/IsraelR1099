/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:20:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/03 12:41:18 by irifarac         ###   ########.fr       */
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
	try
	{
		std::cout << "test increment" << std::endl;
		Bureaucrat	test("hola", 5);

		while (1)
		{
			test.incrementGrade();
			std::cout << test << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	try
	{
		std::cout << "test decrement" << std::endl;
		Bureaucrat	test2("low", 140);

		while (1)
		{
			test2.decrementGrade();
			std::cout << test2 << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	try
	{
		std::cout << "Out of range" << std::endl;
		Bureaucrat	test2("hola2", 1000);
	}
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}

	try
	{
		std::cout << "Bad grade" << std::endl;
		Bureaucrat	test3("hola3", 0);
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
	return (0);
}
