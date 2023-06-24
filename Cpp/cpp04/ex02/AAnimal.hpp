/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:24:36 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/24 17:30:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &obj);
		virtual ~AAnimal(void);
		AAnimal &operator=(const AAnimal &obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
	protected:
		std::string _type;
};
#endif
