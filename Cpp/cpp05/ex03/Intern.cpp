/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:37:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/23 14:32:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern(void)
{
}

std::ostream	&operator<<(std::ostream &output, const Intern &obj)
{
	(void)obj;
	output << "intern print operator called";
	return (output);
}

AForm	*Intern::m_makeShrubbery(const std::string target)
{
	ShrubberyCreationForm	*shrubbery = new ShrubberyCreationForm(target);
	return (shrubbery);
}

AForm	*Intern::m_makePresidential(const std::string target)
{
	PresidentialPardonForm	*presidential = new PresidentialPardonForm(target);
	return (presidential);
}

AForm	*Intern::m_makeRobotomy(const std::string target)
{
	RobotomyRequestForm	*robot = new RobotomyRequestForm(target);
	return (robot);
}

AForm	*Intern::makeForm(std::string frequest, std::string target)
{
	std::string	names[3] = { "robotomy request", "presidential request", "shrubbery request" };
	actions[0] = &Intern::m_makeRobotomy;
	actions[1] = &Intern::m_makePresidential;
	actions[2] = &Intern::m_makeShrubbery;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (frequest == names[i])
		{
			std::cout << "the form exists" << std::endl;
			break ;
		}
		i++;
	}
	std::cout << "i equals " << i << std::endl;
	if (i == 3)
		throw WrongValue("the form doesn't exist");
	action function = actions[i];
	AForm *result = (this->*function)(target);
	return (result);
}
