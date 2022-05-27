/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:35:29 by mporras           #+#    #+#             */
/*   Updated: 2022/01/11 01:35:35 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *str, char c)
{
	size_t	i;
	size_t	words;
	size_t	chars;
	char	prev;

	i = 0;
	prev = -1;
	chars = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
			chars++;
		if (str[i] != c && (prev == c || prev == -1))
			words++;
		prev = str[i];
		i++;
	}
	if (words == 0 && chars > 0)
		words = 1;
	return (words);
}

static char	*ft_strdup_split(char const *src, char c, size_t *i)
{
	char	*dst;
	size_t	len;
	size_t	j;

	len = 0;
	while (src[*(i) + len] && src[*(i) + len] != c)
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	j = 0;
	while (j < len)
	{
		dst[j] = src[*(i)];
		j++;
		*(i) = *(i) + 1;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**rst;
	size_t	deep;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	deep = ft_split_size(s, c);
	rst = (char **)malloc(sizeof(char *) * (deep + 1));
	if (rst == NULL)
		return (NULL);
	while (k < deep)
	{	
		while (s[i] && s[i] == c)
			i++;
		rst[k] = ft_strdup_split(s, c, &i);
		if (rst[k] == NULL)
			return (NULL);
		k++;
	}
	rst[deep] = NULL;
	return (rst);
}
