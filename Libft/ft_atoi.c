/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/15 11:52:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		position;
	int		number;
	int		sign;

	position = 0;
	number = 0;
	sign = 1;
	while (((str[position] >= 9) && (str[position] <= 13))
		|| (str[position] == 32))
		position++;
	if ((str[position] == '-') || (str[position] == '+'))
	{
		if (str[position] == '-')
		sign = -1;
		position++;
	}
	while ((str[position] >= 48) && (str[position] <= 57))
	{	
		number = number * 10 + str[position] - 48;
		position++;
	}
	return (sign * number);
}
