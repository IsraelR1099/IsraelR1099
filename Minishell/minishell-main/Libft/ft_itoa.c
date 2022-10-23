/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:16 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/19 18:40:58 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	static int	i;
	static char	str[4096];

	ft_bzero(str, 4096);
	i = 0;
	if (n > 9)
	{
		ft_itoa(n / 10);
		i++;
	}
	else
		i++;
	str[i - 1] = (n % 10) + 48;
	str[i] = 0;
	return (str);
}
