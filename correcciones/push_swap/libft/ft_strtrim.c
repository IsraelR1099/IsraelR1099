/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:34:20 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 17:51:50 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_trim_fromto(char const *s1, char const *set, size_t *fromto)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_trim_charset(s1[i], set) == 1)
		i++;
	fromto[0] = i;
	fromto[2] = len;
	fromto[1] = fromto[2] - 1;
	while (ft_trim_charset(s1[fromto[1]], set) == 1)
		fromto[1]--;
	if (fromto[0] == len)
	{
		fromto[2] = 0;
		fromto[1] = fromto[0] + 1;
	}
	else
		fromto[2] = (fromto[1] - fromto[0]) + 1;
	if (len == 0)
		fromto[2] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	fromto[3];
	char	*rst;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	i = 0;
	ft_trim_fromto(s1, set, &fromto[0]);
	rst = (char *)malloc(sizeof(char) * (fromto[2] + 1));
	if (rst == NULL)
		return (NULL);
	rst[fromto[2]] = '\0';
	if (fromto[2] == 0)
		return (rst);
	while (i < fromto[2])
	{
		rst[i] = s1[fromto[0]];
		i++;
		fromto[0]++;
	}
	return (rst);
}
