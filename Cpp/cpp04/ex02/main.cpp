/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:06:07 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/24 17:47:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

//test virtual functions and polymorphism
void	testEval(void)
{
	std::cout << "\n" << std::endl;
	Dog basic;

	Dog tmp = basic;
}

int	main(void)
{
	const int n = 6;
	Animal *animal[n];
	//AAnimal test;
	Animal test2;

	for (int i = 0; i < n/2; i++)
		animal[i] = new Dog();
	for (int i = n/2; i < n; i++)
		animal[i] = new Cat();
	for (int i = 0; i < n; i++)
		animal[i]->makeSound();
	for (int i = 0; i < n; i++)
		delete animal[i];
	testEval();
	return (0);
}
