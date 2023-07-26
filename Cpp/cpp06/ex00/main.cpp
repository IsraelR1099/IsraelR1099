/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:31:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 13:46:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int counter, char **str)
{

	if (counter == 2)
	{
		try
		{
			Convert	convert(str);
		}
		catch (std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
	int	a = 42000;
	char	ch;

	ch = static_cast<char>(a);
	std::cout << "ch es: " << ch << std::endl;
	return (0);
}
