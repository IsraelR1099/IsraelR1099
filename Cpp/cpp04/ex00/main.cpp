/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:06:07 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/28 09:35:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	const WrongAnimal	*meta2 = new WrongAnimal();
	const WrongAnimal	*i2 = new WrongCat();

	std::cout << "Dog type: " <<  j->getType() << " " << std::endl;
	std::cout << "Cat type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n" << std::endl;
	std::cout << "Wrong types" << std::endl;
	std::cout << "Cat type: " << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the Wrong animal sound!
	meta2->makeSound();
	delete(meta);
	delete(j);
	delete(i);
	delete(i2);
	delete(meta2);
	return (0);
}
