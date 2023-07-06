/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:55:33 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/06 21:55:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm",
72, 45), m_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target +
"_robotomy", 72, 45), m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :
AForm(obj), m_target(obj.m_target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm
&obj)
{
	AForm::operator=(obj);
	return (*this);
}
