/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:16:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 10:00:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	random;
	AForm	*presidential;
	Bureaucrat anotherTest("anotherTest", 1);

	presidential = random.makeForm("presidential request", "random");
	anotherTest.signAForm(*presidential);
	anotherTest.executeForm(*presidential);

	Intern random2;
	AForm *rrf2 = random2.makeForm("robotomy request", "random_president");
	Bureaucrat anotherTest2("anotherTest2", 1);

	anotherTest2.signAForm(*rrf2);
	anotherTest2.executeForm(*rrf2);

	Intern	random3;
	AForm	*shrubbery = random3.makeForm("shrubbery request", "shruberry");
	Bureaucrat	anotherTest3("anotherTest3", 1);

	anotherTest3.signAForm(*shrubbery);
	anotherTest3.executeForm(*shrubbery);

	try
	{
		Intern		fail;
		AForm		*fail1 = fail.makeForm("fail", "fail");
		Bureaucrat	failTest("failTest", 1);

		failTest.signAForm(*fail1);
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	delete(presidential);
	delete(rrf2);
	delete(shrubbery);
	return (0);
}
