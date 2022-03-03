/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:07:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 14:25:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

int	ft_len(size_t n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	if (base == 16)
		return (len - 1);
	return (len);
}

char	*ft_itoa(size_t n, int base)
{
	char		*ptr;
	size_t		len;
	long int	nbr;

	len = ft_len(n, base);
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
		//printf("el numero es %zu\n", nbr);
		ptr[len] = (nbr % base) + 48;
		nbr /= base;
	}
	//printf("ptr es %s\n", ptr);
	if (n < 0)
		*ptr = '-';
	return (ptr);
}
