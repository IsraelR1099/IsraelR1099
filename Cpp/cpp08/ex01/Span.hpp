/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:26:04 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/13 20:10:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <limits.h>
#include <algorithm>
#include <numeric>

class	Span
{
	public:
		Span(unsigned int n);
		Span(const Span &obj);
		Span	&operator=(const Span &obj);
		~Span(void);

		class	FullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Span is full");
				}
		};
		class	NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Not enough elements to find span");
				}
		};
		void			addNumber(int n);
		void			print(void);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		template <typename T>
		void			addNumber(const typename T::iterator &begin, const typename T::iterator &end)
		{
			if (std::distance(begin, end) > this->m_n)
				throw FullException();
			for (typename T::iterator it = begin; it != end; it++)
			{
				this->addNumber(*it);
			}
		}
	private:
		Span(void);
		unsigned int		m_n;
		std::vector<int>	m_vec;
};

#endif
