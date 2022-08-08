/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/08 12:34:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_isspace(char c)
{
    if ((c == 9) || (c == 13) || (c == 32))
        return (1);
    return (0);
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
        if (str[position] == '-' || str[position] ==  '+')
            return (0);
	}
	if (number > MAX_INT || number < MIN_INT)
		return (0);
	return (sign * number);
}
