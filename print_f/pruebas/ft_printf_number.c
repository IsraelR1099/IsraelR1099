/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:10:07 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 22:46:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(long long int n)
{
	unsigned int	number;
	char			*ptr;

	if (n < 0)
	{
		number = UINT_MAX - n;
		ptr = ft_itoa(number, 10);
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
	size_t	position;

	position = 0;
	ptr = ft_itoa(n, 16);
	printf("ptr es %s\n", ptr);
	printf("len es %ld\n", ft_strlen(ptr));
	while (ptr[position] != '\0')
	{
		if (ptr[position] > 57 && ptr[position] < 64)
		{
			ptr[position] = ptr[position] + 7;
		}
		position++;
	}
	ft_putstr(ptr);
	return (ft_strlen(ptr));
}
	
