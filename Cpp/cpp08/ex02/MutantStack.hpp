/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:19:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/14 11:11:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

//Define a nested iterator class within std::stack. As std::stack internally
//uses a container (by default, it uses std::deque) we can access these
//functions using the "c" member of std::stack
template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &obj) : std::stack<T>(obj) {}
		MutantStack &operator=(const MutantStack &obj) {return
		(std::stack<T>::operator=(obj));}
		~MutantStack(void) {}

		typedef typename std::deque<T>::iterator iterator;
		iterator begin(void) {return (std::stack<T>::c.begin());}
		iterator end(void) {return (std::stack<T>::c.end());}
		iterator rbegin(void) {return (std::stack<T>::c.rbegin());}
		iterator rend(void) {return (std::stack<T>::c.rend());}
		iterator	&operator++(void)
		{
			++(std::stack<T>::c.begin());
			return (*this);
		}
		iterator &operator*(void)
		{
			return (*(std::stack<T>::c.begin()));
		}
};
#endif
