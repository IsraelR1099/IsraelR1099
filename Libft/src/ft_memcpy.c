/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:28 by irifarac          #+#    #+#             */
/*   Updated: 2024/05/12 13:46:00 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t count)
{
	const char	*new_src;
	char		*new_dest;

	new_src = (char *)src;
	new_dest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (count--)
		*new_dest++ = *new_src++;
	return (dest);
}
