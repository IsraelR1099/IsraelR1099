/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:30 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/23 11:39:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal &obj);
		virtual	~Animal(void);
		Animal &operator=(const Animal &obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};
#endif
