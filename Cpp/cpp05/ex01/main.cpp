/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:20:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/05 12:57:58 by irifarac         ###   ########.fr       */
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
	Bureaucrat	test;
	Bureaucrat	test2("test2", 1);

	Form		form1("form1", 1, 1);
	Form		form2("form2", 150, 150);

	std::cout << test << "Tried to sign " << form1 << std::endl;
	test.signForm(form1);

	try
	{
		std::cout << "high test" << std::endl;
		Form	high("high", 0, 10);
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "normal test" << std::endl;
		Form	normal("normal", 10, 10);
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
