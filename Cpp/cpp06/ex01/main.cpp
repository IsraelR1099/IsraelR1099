/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:43:38 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/07 20:31:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		test;
	uintptr_t	serialized;
	Data		*deserialized;

	test.type = 42;
	std::cout << "First one " << &test << std::endl;
	serialized = serialize(&test);
	std::cout << "Serialized " << serialized << std::endl;
	deserialized = deserialize(serialized);
	std::cout << "Deserialized " << deserialized << std::endl;
	if (deserialized == &test)
	{
		std::cout << "Success" << std::endl;
		std::cout << "Deserialized " << deserialized->type << std::endl;
	}
	else
		std::cout << "Fail" << std::endl;
	return (0);
}
