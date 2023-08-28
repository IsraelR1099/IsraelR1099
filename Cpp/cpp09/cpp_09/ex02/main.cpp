/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:25 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/25 11:23:25 by irifarac         ###   ########.fr       */
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
		PmergeMe<std::vector<std::vector<int> >, std::vector<int> >	merge(counter, str);
		clock_t	start = clock();
		merge.mergeInsertionSort();
		clock_t end = clock();
		PmergeMe<std::deque<std::deque<int> >, std::deque<int> >	mergeDeque(counter,str);
		clock_t	start2 = clock();
		mergeDeque.mergeInsertionSort();
		clock_t	end2 = clock();
		double	result = end - start;
		double	result2 = end2 - start2;
		mergeDeque.print("std::vector<int>", "std::deque<int>", result, result2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
