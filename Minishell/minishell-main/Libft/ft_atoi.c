/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 14:18:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == 9) || (c == 13) || (c == 32))
		return (1);
	return (0);
}

static int	ft_check_max(long number, int sign)
{
	if (number > MAX_INT && sign == 1)
		return (0);
	if ((number * sign) < MIN_INT && sign == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		position;
	long	number;
	int		sign;

	position = 0;
	number = 0;
	sign = 1;
	while (ft_isspace(str[position]))
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
		if (str[position] == '-' || str[position] == '+')
			return (0);
	}
	if (!ft_check_max(number, sign))
		return (0);
	return (sign * number);
}
