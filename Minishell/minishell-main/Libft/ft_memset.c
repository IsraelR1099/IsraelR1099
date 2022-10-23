/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:34:59 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/19 13:06:43 by dbekic           ###   ########.fr       */
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
