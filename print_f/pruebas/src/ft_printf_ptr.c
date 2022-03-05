/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:13:36 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/05 14:15:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsigned_len(unsigned long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned long long n, int base)
{
	char				*ptr;
	size_t				len;
	unsigned long long	nbr;

	len = ft_unsigned_len(n, base);
	nbr = n;
	if (n < 0)
	{
		nbr = n * (-1);
		len = len + 1;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (n == 0)
		*ptr = 0 + 48;
	ptr[len] = '\0';
	while (len--)
	{
		ptr[len] = (nbr % base) + 48;
		nbr /= base;
	}
	if (n < 0)
		*ptr = '-';
	return (ptr);
}
