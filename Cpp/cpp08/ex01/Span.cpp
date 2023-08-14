/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:26:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/14 10:23:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : m_n(0), m_vec(0) {
	return;
}

Span::Span(unsigned int n) : m_n(n), m_vec(0) {
	return;
}

Span::Span(const Span &obj)
{
	if (this != &obj)
	{
		this->m_n = obj.m_n;
		this->m_vec = obj.m_vec;
	}
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->m_n = obj.m_n;
		this->m_vec = obj.m_vec;
	}
	return (*this);
}

Span::~Span(void) {
	return;
}

void Span::addNumber(int n)
{
	if (this->m_vec.size() < this->m_n)
	{
		this->m_vec.push_back(n);
	}
	else
		throw (FullException());
}

void	Span::print(void)
{
	std::vector<int>::iterator it = this->m_vec.begin();
	std::vector<int>::iterator ite = this->m_vec.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

unsigned int	Span::shortestSpan(void) const
{

	if (this->m_vec.size() < 2)
		throw (NotEnoughElementsException());
	std::vector<int> tmp(this->m_vec.size());
	std::adjacent_difference(this->m_vec.begin(), this->m_vec.end(), tmp.begin());
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if (*it < 0)
			*it *= -1;
	}
	return (*std::min_element(++tmp.begin(), tmp.end()));
}

unsigned int	Span::longestSpan(void) const
{
	if (this->m_vec.size() < 2)
		throw (NotEnoughElementsException());
	std::vector<int> tmp = this->m_vec;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
