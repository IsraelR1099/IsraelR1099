/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/18 12:24:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t number)
{
	int	position_str1;
	int	position_str2;

	position_str1 = 0;
	position_str2 = 0;
	while (str1[position_str1] == str2[position_str2] && number)
	{	
		position_str1++;
		position_str2++;
		number--;
	}
	if (!number)
		return (0);
	else
		return (str1[position_str1] - str2[position_str2]);
}
