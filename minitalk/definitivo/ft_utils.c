/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:59:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/19 09:38:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	position;

	position = 0;
	sign = 1;
	nbr = 0;
	while (((str[position] >= 9) && (str[position] <= 13))
		|| (str[position] == 32))
		position++;
	if ((str[position] == '-') || (str[position] == '+'))
	{
		if (str[position] == '-')
			sign = -1;
		position++;
	}
	while ((str[position] >= 48) && (str[position] <= 57))
	{
		nbr = (nbr * 10) + str[position] - 48;
		position++;
	}
	return (sign * nbr);
}

size_t	ft_strlen(char *str)
{
	size_t	position;

	position = 0;
	while (*(str + position))
		position++;
	return (position);
}

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
		len = len + 1;
	}
	ptr = malloc(sizeof(char) * (len) + 1);
	if (!(ptr))
		return (NULL);
	if (n == 0)
		*ptr = 0 + 48;
	ptr[len] = '\0';
	while (len--)
	{
		ptr[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		*ptr = '-';
	return (ptr);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
