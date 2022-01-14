/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/14 12:55:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*new_str;
	int		position;
	int		number;
	int		sign;

	new_str = (char *)str;
	position = 0;
	number = 0;
	sign = 1;
	while (new_str[position] == ' ')
		position++;
	if (new_str[position] == 45)
	{
		sign = -1;
		position++;
	}
//	while ((new_str[position]) >= 48 && (new_str[position] <= 57))
	while (ft_isdigit(new_str[position]) == 1)
	{	
		number = number * 10 + new_str[position] - 48;
		position++;
	}
/*	else if (!ft_isdigit(new_str[position]))
	{
		return(number);
	}*/
	return (sign*number);
}


