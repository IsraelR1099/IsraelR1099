/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:31:03 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/21 13:55:44 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	if (size < i)
	{
		while (src[j] != '\0')
			j++;
		return (size + j);
	}
	while (size > 0 && i < size - 1 && src[j])
	dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j++])
			i++;
	return (i);
}
