/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:23:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/15 20:24:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("ShrubberyCreationForm", 145, 137), m_target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target
+ "_shrubbery", 145, 137), m_target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
: AForm(obj), m_target(obj.m_target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const
ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	return (*this);
}

bool	ShrubberyCreationForm::checkRequirement(const Bureaucrat &executor) const
{
	if (executor.getGrade() > 145 || getGradeToExecute() > 137)
		return (0);
	return (1);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!checkRequirement(executor))
		throw AForm::GradeTooLowException("Not enough grade to execute form");
	std::ofstream	outfile((m_target + "_shrubbery").c_str());
	if (!outfile)
		std::cerr << m_target << " could not be opened" << std::endl;
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
		outfile.close();
}
