/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:36:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 15:18:42 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t count)
{
	unsigned int	len_src;
	char			*new_src;
	char			*new_dest;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (!*new_src)
		return (new_dest);
	len_src = ft_strlen(src);
	while (*dest && count >= len_src)
	{
		if (*dest == *src && (ft_strncmp(dest, src, len_src) == 0))
		{
			return ((char *)dest);
		}
		dest += 1;
		count--;
	}
	return (0);
}
