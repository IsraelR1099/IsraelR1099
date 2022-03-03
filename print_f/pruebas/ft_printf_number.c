/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:10:07 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 14:25:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	number;
	char			*ptr;

	if (n < 0)
	{
		number = UINT_MAX - n;
		ptr = ft_itoa(n, 10);
		ft_putstr(ptr);
		return (ft_strlen(ptr));
	}
	else
	{
		ptr = ft_itoa(n, 10);
		ft_putstr(ptr);
	}
	return (ft_strlen(ptr));
}

int	ft_puthex(unsigned int n)
{
	char	*ptr;

	ptr = ft_itoa(n, 16);
	ft_putstr(ptr);
	return (ft_strlen(ptr));
}
	
