/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:27:38 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/25 11:40:34 by irifarac         ###   ########.fr       */
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

float	RPN::Operation(char c, float first, float second)
{
	if (c == '+')
		return (first + second);
	else if (c == '-')
		return (first - second);
	else if (c == '*')
		return (first * second);
	else if (c == '/')
	{
		if (second == 0)
			throw (RPN::BadFormat("ERROR"));
		return (first / second);
	}
	else
		throw (RPN::BadFormat("ERROR"));
	return (0);
}

float	RPN::Calculate(const char *str)
{
	std::stack<float>	ret;
	int					counter_oper;
	int					counter_number;
	float				result;
	float				first;
	float				second;

	counter_number = 0;
	counter_oper = 0;
	result = 0;
	if (strchr("*+/-", str[0]))
			throw (RPN::BadFormat("ERROR"));
	for (int i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]))
		{
			ret.push(str[i] - '0');
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
	if ((counter_number - 1) != (counter_oper))
			throw (RPN::BadFormat("Wrong number of operands"));
	return (ret.top());
}

float	RPN::getResult(void) const
{
	return (m_result);
}

