/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:33:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/11 10:33:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define MAX_VAL 750
void	theirTests(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

int	main(void)
{
	std::cout << "------THEIR-TESTS--------" << std::endl;
	theirTests();
	std::cout << "\n";

	std::cout << "----------MY TESTS-------" << std::endl;
	Array<int> d;
	Array<int> a(5);
	Array<float> b(5);
	Array<std::string> c(5);

	for (int i = 0; i < 5; i++)
	{
		a[i] = rand() % 10;
		b[i] = rand() % 10;
	}
	for (int i = 0; i < 5; i++)
	{
		c[i] = "string";
	}
	std::cout << "Array a: ";
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	std::cout << "Array b: ";
	for (int i = 0; i < 5; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	std::cout << "Array c: ";
	for (int i = 0; i < 5; i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
	std::cout << "Array d: ";
	try
	{
		for (int i = 0; i < 1; i++)
			std::cout << d[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Array a: ";
		for (int i = 0; i < 6; i++)
			std::cout << a[i] << " ";
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	return (0);
}
