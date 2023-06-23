/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:39:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/23 11:46:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain &obj);
		~Brain(void);
		Brain	&operator=(const Brain &obj);
	protected:
		std::string	ideas[100];
};
