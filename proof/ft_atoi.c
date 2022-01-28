/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:55:48 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/17 17:56:01 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_limit(long int n, const char *r, int sign)
{
	long int	set_min;
	long int	set_max;

	set_min = ((n * 10) + (*r - '0')) * sign;
	if (set_min < -2147483648)
		return (0);
	set_max = ((n * 10) + (*r - '0')) * sign;
	if (set_max > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			marker;
	int			s;
	long int	res;
	int			limit_set;

	marker = 0;
	s = 1;
	res = 0;
	while ((str[marker] >= '\t' && str[marker] <= '\r') || str[marker] == ' ')
		marker++;
	if ((str[marker] == '-') || (str[marker] == '+'))
	{
		if (str[marker] == '-')
			s *= -1;
		marker++;
	}
	while (str[marker] != '\0' && str[marker] >= '0' && str[marker] <= '9')
	{
		limit_set = ft_limit (res, str, s);
		if (limit_set == 0 || limit_set == -1)
			return (limit_set);
		res = (str[marker] - '0') + (res * 10);
		marker++;
	}
	return (res * s);
}
