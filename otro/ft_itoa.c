/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:34:42 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/25 14:40:46 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_calcul_digits(int n)
{
	int	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

static char	*ft_get_str(char *res, int num_digits, int sign, int n)
{
	char	c;

	if (sign == -1)
	{
		res[num_digits + 1] = '\0';
		while (num_digits > 0)
		{
			res[0] = '-';
			c = n % 10 + 48;
			res[num_digits--] = c;
			n = n / 10;
		}
	}
	else
	{
		res[num_digits] = '\0';
		while (num_digits > 0)
		{
			c = n % 10 + 48;
			res[num_digits - 1] = c;
			n = n / 10;
			num_digits--;
		}
	}
	return (res);
}

static char	*ft_min_int(void)
{
	char	*result;

	result = malloc(sizeof(char) * 12);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;
	int		sign;

	if (n == -2147483648)
	{
		res = ft_min_int();
		return (res);
	}
	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	num_digits = ft_calcul_digits(n);
	if (sign == -1)
		res = malloc(sizeof(char) * num_digits + 2);
	else
		res = malloc(sizeof(char) * num_digits + 1);
	if (!res)
		return (NULL);
	res = ft_get_str(res, num_digits, sign, n);
	return (res);
}
