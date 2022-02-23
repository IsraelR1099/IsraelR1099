/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:15:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 13:37:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	position;

	position = 0;
	if (s != NULL && f != NULL)
	{
		while (s[position] != '\0')
		{
			(*f)(position, s + position);
			position++;
		}
	}
}
