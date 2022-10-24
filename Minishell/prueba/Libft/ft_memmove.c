/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:04:10 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/24 12:10:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char	*new_dest;
	char	*new_src;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (new_dest > new_src)
	{
		printf("entro aqui\n");
		while (count--)
		{
			*(new_dest + count) = *(new_src + count);
		}
	}
	else
	{
		printf("entro alla\n");
		while (count--)
		{
		*new_dest++ = *new_src++;
		}
	}
	return (dest);
}
