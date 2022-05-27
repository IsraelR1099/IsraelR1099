/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:10:38 by mporras-          #+#    #+#             */
/*   Updated: 2022/01/11 13:10:44 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rst;
	size_t	len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (rst == NULL)
		return (NULL);
	while (s[i])
	{
		rst[i] = (*f)(i, s[i]);
		i++;
	}
	rst[i] = 0;
	return (rst);
}
