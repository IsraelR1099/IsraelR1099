# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Span.ipp                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:53:41 by irifarac          #+#    #+#              #
#    Updated: 2023/08/13 18:35:43 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef SPAN_IPP
# define SPAN_IPP

#include "Span.hpp"

template <typename T>
void Span::addNumber(const typename T::iterator &begin, const typename T::itarator &end)
{
	for (InputIterator it = first; it != last; it++)
	{
		this->addNumber(*it);
	}
}
#endif
