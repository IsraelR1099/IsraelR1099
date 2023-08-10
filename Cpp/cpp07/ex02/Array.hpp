/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/10 20:56:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <time.h>
#include <stdlib.h>

template <typename T>
class	Array
{
	public:
		Array(void) : m_array(NULL), m_size(0) {}
		explicit Array(unsigned int n) : m_array(new T[n]), m_size(n) {}
		Array(const Array &obj) : m_array(new T[obj.m_size]),
		m_size(obj.m_size)
		{
			for (unsigned int i = 0; i < m_size; i++)
				m_array[i] = obj.m_array[i];
		}
		~Array(void)
		{
			if (m_array)
				delete [] m_array;
		}
		class	IndexOutOfBoundException : public std::exception
		{
			public:
			const char *what() const throw()
			{
				return ("Index out of bound");
			}
		};
		Array &operator=(const Array &obj)
		{
			if (this != obj)
			{
				if (m_array)
					delete [] m_array;
				m_array = new T[obj.m_size];
				m_size = obj.m_size;
				for (unsigned int i = 0; i < m_size; i++)
					m_array[i] = obj.m_array[i];
			}
			return (*this);
		}
		T &operator[](const unsigned int index)
		{
			if (index >= m_size)
				throw (IndexOutOfBoundException());
			return (m_array[index]);
		}
		unsigned int size(void) const
		{
			return (m_size);
		}
	private:
		T				*m_array;
		unsigned int	m_size;
};
#endif
