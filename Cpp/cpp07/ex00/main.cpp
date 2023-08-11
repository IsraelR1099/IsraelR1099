/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:54:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/11 10:08:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "----------INT-----------" << std::endl;
	int	c1 = -111;
	int	d1 = 10;
	std::cout << "min(1000, 10) = " << min<int>(c1, d1) << std::endl;
	std::cout << "max(1000, 10) = " << max<int>(c1, d1) << std::endl;
	::swap(c1, d1);
	std::cout << "c1 = " << c1 << ", d1 = " << d1 << std::endl;

	std::cout << "--------FLOAT-------------" << std::endl;
	float	c2 = -111.111;
	float	d2 = 10.10;
	std::cout << "min(-111.111, 10.10) = " << min<float>(c2, d2) << std::endl;
	std::cout << "max(-111.111, 10.10) = " << max<float>(c2, d2) << std::endl;
	::swap(c2, d2);
	std::cout << "c2 = " << c2 << ", d2 = " << d2 << std::endl;

	std::cout << "--------DOUBLE-------------" << std::endl;
	double	c3 = -42.00000001;
	double	d3 = 42.42;
	std::cout << "min(-111.111, 10.10) = " << min<double>(c3, d3) << std::endl;
	std::cout << "max(-111.111, 10.10) = " << max<double>(c3, d3) << std::endl;
	::swap(c3, d3);
	std::cout << "c3 = " << c3 << ", d3 = " << d3 << std::endl;

	std::cout << "--------CHAR-------------" << std::endl;
	char	c4 = 'a';
	char	d4 = 'z';
	std::cout << "min('a', 'z') = " << min<char>(c4, d4) << std::endl;
	std::cout << "max('a', 'z') = " << max<char>(c4, d4) << std::endl;
	::swap(c4, d4);
	std::cout << "c4 = " << c4 << ", d4 = " << d4 << std::endl;

	std::cout << "--------STRING-------------" << std::endl;
	std::string	c5 = "Hello";
	std::string	d5 = "World";
	std::cout << "min('Hello', 'World') = " << min<std::string>(c5, d5) << std::endl;
	std::cout << "max('Hello', 'World') = " << max<std::string>(c5, d5) << std::endl;
	::swap(c5, d5);
	std::cout << "c5 = " << c5 << ", d5 = " << d5 << std::endl;

	std::cout << "--------RANDOM-------------" << std::endl;
	float	c6 = (float)rand() / (float)RAND_MAX;
	float	d6 = (float)rand() / (float)RAND_MAX;
	std::cout << "min(" << c6 << ", " << d6 << ") = " << min<float>(c6, d6) << std::endl;
	std::cout << "max(" << c6 << ", " << d6 << ") = " << max<float>(c6, d6) << std::endl;
	::swap(c6, d6);
	std::cout << "c6 = " << c6 << ", d6 = " << d6 << std::endl;
	return (0);
}
