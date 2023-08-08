/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:50:39 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/08 17:47:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <time.h>
# include <ctime>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
