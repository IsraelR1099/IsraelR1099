/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:47:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/02 14:19:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch, int flag_quote)
{
	int	position;

	position = 0;
//	printf("flag_quote en strchr es %d y tokens %s y ch %d\n", flag_quote, str, ch);
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch
			&& flag_quote != 1)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch
		&& flag_quote != 1)
		return ((char *)str + position);
	return (0);
}
