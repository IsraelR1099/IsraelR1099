/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:47:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/09 14:14:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch)
		{
			return ((char *)str + position);
		}
		position++;
	}
	if (str[position] == (char)ch)
		return ((char *)str + position);
	return (0);
}
