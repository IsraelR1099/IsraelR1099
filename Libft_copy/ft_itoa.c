/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:16 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 14:21:47 by irifarac         ###   ########.fr       */
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

	len = ft_len(n);
	nbr = n;
	if (n < 0)
	{
		nbr = nbr * (-1);
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	while (len--)
	{
		ptr[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	ptr[ft_len(n) + 1] = '\0';
	return (ptr);
}
