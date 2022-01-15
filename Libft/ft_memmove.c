/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:04:10 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/15 12:44:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char	*new_dest;
	char	*new_src;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (new_dest > new_src)
	{
		while (count--)
		{
			*(new_dest + count) = *(new_src + count);
		}
	}
	else
	{
		while (count--)
		{
		*new_dest++ = *new_src++;
		}
	}
	return (dest);
}
