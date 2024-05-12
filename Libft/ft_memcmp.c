/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:21:24 by irifarac          #+#    #+#             */
/*   Updated: 2024/05/12 13:43:33 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	unsigned const char	*new_str1;
	unsigned const char	*new_str2;
	int					position_str1;
	int					position_str2;

	new_str1 = (const unsigned char *)str1;
	new_str2 = (const unsigned char *)str2;
	position_str1 = 0;
	position_str2 = 0;
	while (count)
	{
		if (new_str1[position_str1] != new_str2[position_str2])
			return (new_str1[position_str1] - new_str2[position_str2]);
		position_str1++;
		position_str2++;
		count--;
	}
	if (!count)
		return (0);
	return (0);
}
