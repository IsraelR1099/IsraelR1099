/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:53:16 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/20 14:02:33 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[ft_strlen(s1) - i - 1]) == 0)
			break ;
		i++;
	}
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	marker;
	size_t	invmarker;
	char	*res;

	marker = ft_begin(s1, set);
	invmarker = ft_end(s1, set);
	if (marker >= invmarker)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (invmarker - marker + 1));
	if (!s1 || !res)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	ft_strlcpy(res, s1 + marker, invmarker - marker + 1);
	return (res);
}
