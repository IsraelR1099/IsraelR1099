/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:19:54 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 21:01:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	position;

	position = ft_strlen(str) + 1;
	while (position > 0)
	{
		position--;
		if (str[position] == (unsigned char)ch)
		{
			return ((char *)str + position);
		}
	}
	return (0);
}
