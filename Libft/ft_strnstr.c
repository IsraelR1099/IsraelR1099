/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:36:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/12 14:01:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *dest, const char *src, size_t count)
{
	int		position_dest;
	int		position_src;
	char	*new_src;
	char	*new_dest;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (!*new_src)
	{
		return (new_dest);
	}
	position_dest = 0;
	while ((dest[position_dest] != '\0') && count)
	{
		position_src = 0;
		while (dest[position_dest + position_src] == src[position_src])
		{
			position_src++;
			if (src[position_src] == '\0')
			{
				return (&new_dest[position_dest]);
			}
		}
		position_dest++;
		count--;
	}
	return (0);
}
