/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:46:08 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 13:26:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	beginning(const char *s1, const char *set)
{
	int		position;

	position = 0;
	while (ft_strchr((char *)set, s1[position]) != NULL)
	{
		position++;
	}
	return (position);
}

int	end(const char *s1, const char *set)
{
	int	lens1;
	int	counter;

	counter = 0;
	lens1 = ft_strlen((char *)s1) - 1;
	while (lens1 >= 0 && ft_strchr((char *)set, s1[lens1]) != NULL)
	{
		lens1--;
	}
	return (lens1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*new_str;
	int		first;
	int		last;

	new_str = (char *)s1;
	first = beginning(s1, set);
	last = end(s1, set);
	if (first >= last)
		return (ft_strdup(""));
	ptr = malloc(1 * (last - first + 1));
	if (!ptr || !s1)
		return (0);
	if (!set)
		return ((char *)s1);
	ft_strlcpy(ptr, s1 + first, (last - first + 1));
	return (ptr);
}