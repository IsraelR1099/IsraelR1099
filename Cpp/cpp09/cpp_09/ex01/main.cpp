/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:39:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/21 13:04:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int counter, char **str)
{
	if (counter == 2)
	{
		try
		{
			RPN	test2(str[1]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	(void)str;
	return (0);
}
