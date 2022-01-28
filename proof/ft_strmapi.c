/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:51:41 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/21 15:17:41 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	marker;

	res = ft_strdup(s);
	if (!s || !res || !f)
		return (0);
	marker = 0;
	while (res[marker])
	{
		res[marker] = f(marker, res[marker]);
			marker++;
	}
	return (res);
}
