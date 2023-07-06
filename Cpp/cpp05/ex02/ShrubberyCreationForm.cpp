/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:23:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/06 20:53:25 by irifarac         ###   ########.fr       */
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
