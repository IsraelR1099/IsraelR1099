/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:19:54 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/07 11:24:30 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int number)
{
	size_t	length;

	length = 0;
	if (number <= 0)
		length++;
	while (number)
	{
		length++;
		number = number / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*string;
	long	number;

	length = ft_num_len(n);
	number = n;
	string = malloc(sizeof(char) * length + 1);
	if (!string)
		return (NULL);
	if (number < 0)
	{
		string[0] = '-';
		number = -number;
	}
	if (number == 0)
		string[0] = '0';
	string[length--] = '\0';
	while (number)
	{
		string[length] = number % 10 + '0';
		length--;
		number = number / 10;
	}
	return (string);
}
