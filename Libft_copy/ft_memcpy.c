/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/28 14:18:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	const char	*new_src;
	char		*new_dest;

	new_src = (char *)src;
	new_dest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (count--)
	{
		*new_dest++ = *new_src++;
	}
	return (dest);
}
