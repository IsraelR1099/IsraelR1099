/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:28:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/11 21:06:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class	NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Element not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	if (container.empty())
		throw (NotFoundException());
	typename T::iterator it = std::find(begin, end, n);
	if (it != end)
		return (it);
	else
		throw (NotFoundException());
}
#endif
