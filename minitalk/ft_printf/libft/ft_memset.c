/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:34:59 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/15 10:00:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*dest, int ch, size_t count)
{
	unsigned int	position;
	char			*new_dest;

	new_dest = (char *)dest;
	position = 0;
	while (position < count)
	{
		new_dest[position] = (char)ch;
		position++;
	}
	return (new_dest);
}
