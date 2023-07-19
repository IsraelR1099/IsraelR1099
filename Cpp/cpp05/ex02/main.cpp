/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:16:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 09:46:39 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat test1("test1", 5);
	Bureaucrat test2("test2", 6);
	Bureaucrat test3("test3", 25);
	Bureaucrat test4("test4", 46);
	Bureaucrat test5("test5", 125);
	Bureaucrat test6("test6", 1);

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	std::cout << test4 << std::endl;
	std::cout << test5 << std::endl;

	std::cout << "---------------------" << std::endl;
	test1.executeForm(ShrubberyCreationForm("home"));
	test2.executeForm(ShrubberyCreationForm("home2"));

	test3.executeForm(RobotomyRequestForm("home3"));
	test4.executeForm(RobotomyRequestForm("home4"));

	test5.executeForm(PresidentialPardonForm("home5"));
	test6.executeForm(PresidentialPardonForm("home6"));

	std::cout << "---------------------" << std::endl;
	ShrubberyCreationForm	form1("home");
	RobotomyRequestForm		form2("home2");

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	test1.signAForm(form1);
	test2.signAForm(form2);

	std::cout << "---------------------" << std::endl;
	test1.executeForm(form1);
	test2.executeForm(form2);
	return (0);
}
