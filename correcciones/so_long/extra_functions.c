/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fucntions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:00:00 by marza-ga          #+#    #+#             */
/*   Updated: 2021/11/05 12:00:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	calculate_itoa_array_size(int n);
static char	*case_zero(void);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		array_size;
	int		sign;
	int		digit;

	sign = 1;
	if (n == 0)
		return (case_zero());
	if (n < 0)
		sign = -1;
	array_size = calculate_itoa_array_size(n);
	ptr = malloc(sizeof(char) * array_size);
	if (!ptr)
		return (NULL);
	ptr[--array_size] = '\0';
	while (n)
	{
		digit = n % 10 * sign;
		n = n / 10;
		ptr[--array_size] = '0' + digit;
	}
	if (sign == -1)
		ptr[0] = '-';
	return (ptr);
}

static int	calculate_itoa_array_size(int n)
{
	int	array_size;

	array_size = 1;
	if (n < 0)
		array_size++;
	while (n)
	{
		n = n / 10;
		array_size++;
	}
	return (array_size);
}

static char	*case_zero(void)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * 2);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit[10];
	int		sign;
	int		count;

	if (!fd)
		return ;
	count = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		while (n)
		{
			digit[count++] = '0' + (n % 10 * sign);
			n = n / 10;
		}
		while (count != 0)
			write(fd, &digit[--count], 1);
	}
}
