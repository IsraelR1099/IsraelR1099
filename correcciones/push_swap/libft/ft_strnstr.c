/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:40:18 by mporras           #+#    #+#             */
/*   Updated: 2022/01/10 22:40:38 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	k;
	size_t	len_needle;
	char	*sheaf;

	if (haystack == needle)
		return ((char *)haystack);
	i = 0;
	len_needle = ft_strlen(needle);
	sheaf = (char *)haystack;
	if (len_needle == 0)
		return (sheaf);
	while (sheaf[i] && i < loc)
	{
		if (sheaf[i] == needle[0])
		{
			k = 0;
			while (sheaf[i + k] && sheaf[i + k] == needle[k] && i + k < loc)
				k++;
			if (k == len_needle)
				return (&sheaf[i]);
		}
		i++;
	}
	return (NULL);
}
