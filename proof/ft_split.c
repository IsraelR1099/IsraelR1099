/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:33:14 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/28 13:04:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcountr(char const *s, char c)
{
	unsigned int	i;
	int				countr;

	i = 0;
	countr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			countr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (countr);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	marker;
	char	*s2;

	marker = 0;
	s2 = malloc (ft_strlen(s) * n + 1);
	if (!s)
		return (0);
	while (marker < (ft_strlen(s) + 1))
	{
		((unsigned char *)s2)[marker] = ((unsigned char *)s)[marker];
		marker++;
	}
	s2[n] = '\0';
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	int		m;
	int		m2;
	int		t;
	char	**tab;

	m = 0;
	t = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_wcountr(s, c) + 1));
	if (!tab)
		return (0);
	while (s[m] != '\0')
	{
		while (s[m] == c)
			m++;
		m2 = m;
		while (s[m] && s[m] != c)
			m++;
		if (m > m2)
		{
			tab[t] = ft_strndup(&s[m2], m - m2);
			t++;
		}
	}
	tab[t] = NULL;
	return (tab);
}
