/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:27:38 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/21 13:51:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::stack<char> &init)
{
	m_init = init;
}

RPN::RPN(const char *str)
{
	m_result = Calculate(str);
}


RPN::RPN(const RPN &obj) : m_init(obj.m_init)
{
}

RPN	&RPN::operator=(const RPN &obj)
{
	if (this == &obj)
		return (*this);
	m_init = obj.m_init;
	return (*this);
}

RPN::~RPN(void)
{
}

int	RPN::Calculate(const char *str) const
{
	std::stack<char>	ret;
	int					counter_oper;
	int					counter_number;
	int					first;
	int					second;

	counter_number = 0;
	counter_oper = 0;
	for (int i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]))
		{
			ret.push(str[i]);
			counter_number++;
		}
		else if (strchr("*+/-", str[i]))
		{
			second = ret.top();
			ret.pop();
			first = ret.top();
			ret.pop();
			result = Operation(str[i], first, second);
			ret.push(result);
			counter_oper++;
		}
		else if (str[i] == ' ')
			continue ;
		else
			throw (RPN::BadFormat("ERROR"));
	}
	std::cout << "number es: " << counter_number << std::endl;
	std::cout << "operand es : " << counter_oper << std::endl;
	if ((counter_number - 1) != (counter_oper))
			throw (RPN::BadFormat("Wrong number of operands"));
	return (0);
}


