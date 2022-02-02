/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:03:55 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/21 19:33:04 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *library, const char *book, size_t n)
{
	size_t	i;
	size_t	j;

	if (book[0] == '\0')
		return ((char *)library);
	j = ft_strlen(book);
	i = 0;
	while (library[i] != '\0' && (i + j) <= n)
	{
		if (library[i] == book[0])
		{
			if (ft_strncmp(library + i, book, j) == 0)
				return ((char *)(library + i));
		}
			i++;
	}
	return (NULL);
}
