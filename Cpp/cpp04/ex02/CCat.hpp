/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:26:03 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/28 09:48:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CCAT_HPP
# define CCAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	CCat : public AAnimal
{
	public:
		CCat(void);
		CCat(const CCat &obj);
		~CCat(void);
		CCat	&operator=(const CCat &obj);

		std::string	getType(void) const;
		void		makeSound(void) const;
	private:
		Brain	*_brain;
};
#endif
