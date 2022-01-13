/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:01:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 14:21:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int ch, size_t count)
{
	const char		*new_str;
	unsigned int	position;

	new_str = (char *)str;
	position = 0;
	while (position <= count)
	{
		if (new_str[position] == ch)
		{
			return ((void *)str);
		}
		position++;
	}
	return (0);
}
