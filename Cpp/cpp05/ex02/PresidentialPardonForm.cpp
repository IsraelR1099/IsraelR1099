/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:06:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/06 21:11:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("PresidentialPardonForm", 25, 5), m_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm(target + "presidential", 25, 5), m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
&obj) : AForm(obj), m_target(obj.m_target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}
PresidentialPardonForm	&PresidentialPardonForm::operator=(const
PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	return (*this);
}
