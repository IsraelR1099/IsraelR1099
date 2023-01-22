/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/22 15:26:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned int	position;
	char			*new_dest;

	new_dest = (char *)dest;
	position = 0;
	while (position < count)
	{
		new_dest[position] = (char)ch;
		position++;
	}
	return (new_dest);
}

float	ft_fatoi(char *str)
{
	float	nbr;
	int		i;
	int		sign;
	int		exp;

	sign = 1;
	i = 0;
	exp = 0;
	nbr = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57 && str[i] != '\0'))
	{
		printf("nbr es %f, y caracter %c\n", nbr, str[i]);
		nbr = (nbr * 10) + str[i] - 48;
		i++;
		if (str[i] == 46)
			i++;
		exp++;
	}
	nbr /= pow(10, exp - 1);
	return (sign * nbr);
}

int	ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57 && str[i]))
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (sign * nbr);
}

