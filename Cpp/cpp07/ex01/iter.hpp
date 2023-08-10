/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:15:27 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/09 20:33:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *array, int length, void (*f)(const T &x))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}
#endif
