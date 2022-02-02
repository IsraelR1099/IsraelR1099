/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:49:03 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/25 14:55:53 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_find_char(char const *set, char c)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	i;
	size_t	len;
	char	*res;
	size_t	a;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_find_char(set, s1[i]) == 1)
		i++;
	len = ft_strlen(s1);
	while (len - 1 >= i && len - 1 >= 0
		&& ft_find_char(set, s1[len - 1]) == 1)
		len--;
	res = malloc(len - i + 1);
	if (!res)
		return (NULL);
	a = 0;
	while (i < len)
		res[a++] = s1[i++];
	res[a] = '\0';
	return (res);
}
