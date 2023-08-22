/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:25 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/22 17:38:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int counter, char **str)
{
	if (counter < 2)
	{
		std::cout << "Usage: ./PmergeMe [numbers]" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe	merge(counter, str);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
