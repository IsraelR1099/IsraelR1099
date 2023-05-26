/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:18:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/26 13:46:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string.h>
# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(void);
		~Weapon(void);
		const std::string	&getType();
		void				setType(std::string name);
	private:
		std::string	type;
};
#endif
