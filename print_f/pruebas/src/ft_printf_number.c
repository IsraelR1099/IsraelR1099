/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:10:07 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/04 14:14:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunsigned(long long int n)
{
	unsigned int	number;
	char			*ptr;
	int				len;

	if (n < 0)
	{
		number = UINT_MAX - n;
		ptr = ft_itoa(number, 10);
		ft_putstr(ptr);
		len = ft_strlen(ptr);
		free(ptr);
		return (len);
	}
	else
	{
		ptr = ft_itoa(n, 10);
		ft_putstr(ptr);
		len = ft_strlen(ptr);
	}
	free(ptr);
	return (len);
}

int	ft_puthex(unsigned int n, int str)
{
	char	*ptr;
	size_t	position;
	int		len;

	position = 0;
	ptr = ft_itoa(n, 16);
	while (ptr[position] != '\0')
	{
		if (ptr[position] > 57 && ptr[position] < 64)
		{
			ptr[position] = ptr[position] + 7;
			if (str == 'x')
				ptr[position] = ft_tolower(ptr[position]);
		}
		position++;
	}
	ft_putstr(ptr);
	len = ft_strlen(ptr);
	free(ptr);
	return (len);
}
	
