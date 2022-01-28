/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:25:17 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/27 17:02:01 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int nb)
{
	int		len;

	if (nb <= 0)
		len = 1;
	else
		len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		marker;
	int		len;
	int		len2;
	char	*result;

	marker = 0;
	len = ft_nbr_len(n);
	len2 = len;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy (result, "-2147483648", 12));
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
		marker++;
		len--;
	}
	while (marker < len2)
		result[marker++] = ((n / ft_div(len--)) % 10) + 48;
	result[marker] = '\0';
	return (result);
}
