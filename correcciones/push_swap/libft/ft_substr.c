/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:15:24 by mporras           #+#    #+#             */
/*   Updated: 2022/01/11 01:15:26 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max;
	char	*rst;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (len > (max - start))
		len = max - start;
	if (start > max)
		len = 0;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (rst == NULL)
		return (NULL);
	if (len == 0)
		rst[0] = '\0';
	else
		ft_strlcpy(rst, &((char *)s)[start], len + 1);
	return (rst);
}
