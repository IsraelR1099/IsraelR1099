/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:16 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 14:43:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	nbr;
	int			counter;

	len = ft_len(n);
	nbr = n;
	counter = 0;
	if (n < 0)
	{
		nbr = nbr * (-1);
		len++;
		counter++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	while (counter < len)
	{
		ptr[counter] = (nbr % 10) + 48;
		nbr /= 10;
		counter++;
	}
	if (n < 0)
		ptr[0] = '-';
	ptr[ft_len(n) + 1] = '\0';
	return (ptr);
}
