/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:52:18 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 13:06:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	int				len;
	unsigned int	position;

	len = ft_strlen(s);
	ptr = malloc (sizeof(char) * len + 1);
	if (!ptr || !f || !s)
		return (0);
	position = 0;
	ft_strlcpy(ptr, s, len + 1);
	while (ptr[position] != '\0')
	{
		ptr[position] = f(position, ptr[position]);
		position++;
	}
	ptr[position + 1] = '\0';
	return (ptr);
}
