/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:34:17 by mporras-          #+#    #+#             */
/*   Updated: 2022/01/11 12:34:22 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_magnitude(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{	
		len = 1;
		nbr = n * -1;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				mag;
	char			*rst;
	unsigned int	nbr;

	mag = ft_magnitude(n);
	rst = (char *)malloc(sizeof(char) * (mag + 1));
	if (rst == NULL)
		return (NULL);
	rst[mag] = '\0';
	if (n < 0)
	{
		rst[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr == 0)
		rst[0] = '0';
	while (mag-- > 0 && nbr > 0)
	{
		rst[mag] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (rst);
}
