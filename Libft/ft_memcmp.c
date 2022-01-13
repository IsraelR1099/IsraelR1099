/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:21:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 14:39:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	char	*new_str1;
	char	*new_str2;
	int		position_str1;
	int		position_str2;

	new_str1 = (char *)str1;
	new_str2 = (char *)str2;
	position_str1 = 0;
	position_str2 = 0;
	while (new_str1[position_str1] == new_str2[position_str2] && count)
	{
		position_str1++;
		position_str2++;
		count--;
	}
	if (!count)
		return (0);
	else
		return (new_str1[position_str1] - new_str2[position_str2]);
}
