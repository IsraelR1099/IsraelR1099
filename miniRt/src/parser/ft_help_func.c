/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:37:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

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

float	ft_fatoi(char **str)
{
	float	nbr;
	int		sign;
	int		exp;
	int		flag;
	int		j;

	sign = 1;
	exp = 0;
	nbr = 0;
	flag = 0;
	j = 0;
	if (**str == '-')
	{
		*str = *str + 1;
		sign = -1;
	}
	while ((**str >= 48 && **str <= 57 && **str != '\0') || **str == '.' )
	{
	/*	nbr = (nbr * 10) + **str - 48;
		*str = *str + 1;
		if (**str == 46)
		{
			*str = *str + 1;
			flag = 1;
		}
		exp++;*/
		if (**str != '.')
		{
			nbr = (nbr * 10) + **str - '0';
			if (flag == 1)
				j--;
		}
		if (**str == '.')
		{
			if (flag == 1)
				return (0);
			flag = 1;
		}
		*str = *str + 1;
	}
	if (flag == 0)
		exp--;
//	nbr /= pow(10, exp - 1);
	nbr = nbr * pow(10, j);
	return (sign * nbr);
}

int	ft_atoi(char **str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		*str = *str + 1;
	}
	while (**str >= 48 && **str <= 57 && **str != '\0')
	{
		nbr = (nbr * 10) + **str - 48;
		*str = *str + 1;
	}
	return (sign * nbr);
}
