/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:04:10 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 13:49:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*new_dest;
	const char	*new_src;

	new_dest = (char *)dest;
	new_src = (char *)src;

	if (new_dest > new_src)
	{
		new_dest[count - 1] = new_src[count - 1];
		count--;
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
