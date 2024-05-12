/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2024/05/11 20:51:31 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		sign;

	number = 0;
	sign = 1;
	while (((*str >= 9) && (*str <= 13)) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = number * 10 + *str - 48;
		str++;
	}
	return (sign * number);
}
