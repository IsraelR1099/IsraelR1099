/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:35:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/16 13:46:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int counter, char **str)
{
	if (counter != 2)
	{
		std::cout << "Invalid number of arguments\n";
	}
	Date	my_date(str[1]);

	return (0);
}
