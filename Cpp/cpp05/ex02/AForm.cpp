/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:12:17 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/07 11:51:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : m_name("Default"), m_signed(false), m_gradeToSign(150),
m_gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
m_name(name), m_signed(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToSign > 150)
		throw (GradeTooLowException("Grade too low constructor"));
	if (gradeToExecute < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToExecute > 150)
		throw (GradeTooLowException("Grade too low constructor"));
}

AForm::AForm(AForm const &obj) : m_name(obj.m_name), m_signed(obj.m_signed),
m_gradeToSign(obj.m_gradeToSign), m_gradeToExecute(obj.m_gradeToExecute)
{
}

AForm::~AForm(void)
{
	return ;
}

AForm	&AForm::operator=(AForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->m_signed = obj.m_signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->m_name);
}

bool	AForm::getSigned(void) const
{
	return (this->m_signed);
}

int		AForm::getGradeToSign(void) const
{
	return (this->m_gradeToSign);
}

int		AForm::getGradeToExecute(void) const
{
	return (this->m_gradeToExecute);
}

//If the grade of the bureaucrat is high enough to sign the form, it sets signed to true
void AForm::beSigned(const Bureaucrat &obj)
{
	if (this->m_gradeToSign < static_cast<int>(obj.getGrade()))
		throw (GradeTooLowException("Grade too low to sign"));
	this->m_signed = true;
}

void	AForm::createDerived(const Bureaucrat &executor)
{
	if (checkRequirement(executor))
	{
			execute(executor);
	}
	else
		std::cerr << "Not able to create the derived object" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const AForm &obj)
{
	output << "AForm " << obj.getName() << " is ";
	if (obj.getSigned())
		output << "signed";
	else
		output << "not signed";
	output << " and requires grade " << obj.getGradeToSign() << " to sing and "
	<< obj.getGradeToExecute() << " to execute" << std::endl;
	return (output);
}
