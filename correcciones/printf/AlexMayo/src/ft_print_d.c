/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:58:11 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/24 11:58:24 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int	ft_print_d(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_string(num);
	free(num);
	return (len);
}
