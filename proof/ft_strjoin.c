/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:35:01 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/19 17:44:20 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	size_t	marker;
	size_t	i;
	char	*res;

	marker = 0;
	i = 0;
	res = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !res)
		return (0);
	while (s1[marker] != '\0')
	{
		res[marker] = s1[marker];
		marker++;
	}
	while (s2[i] != '\0')
	{
		res[marker + i] = s2[i];
		i++;
	}
	res[marker + i] = '\0';
	return (res);
}
