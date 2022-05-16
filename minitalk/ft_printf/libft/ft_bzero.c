/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:10:18 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/15 09:41:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	position;
	char			*new_s;

	new_s = (char *)s;
	position = 0;
	while (position < n)
	{
		new_s[position] = '\0';
		position++;
	}
}
